#include "wsdriver.h"

#include <filesystem>
#include <string>

WSDriver::WSDriver(){
    FUN();
    this->_nextLVId = 0;
}

WSDriver::~WSDriver(){
    FUN();
}

bool WSDriver::fetch(std::vector<ParseBlock> blocks, size_t* pos, uint* nextGVId){
    FUN();

    if (blocks.at(*pos).getBlockAt(0) != "driver"){
        LOGE("Tried to fetch a line not containing a driver!");
        return false;
    }

    this->_name = blocks.at(*pos).getBlockAt(1);

    (*pos)++;

    while (blocks.at(*pos).getBlockAt(0) != "/driver"){
        WSValue nvalue;
        if(nvalue.fromParsedBlock(blocks.at(*pos), this->_nextLVId, *nextGVId)){
            this->_values.push_back(nvalue);
            this->_nextLVId++;
            (*nextGVId)++;
            (*pos)++;
        }else{
            LOGE("Failed parsing a value, stopping parse...");
            return false;
        }
    }

    LOGD("Fetched one driver!");
    return true;
}

bool WSDriver::queryValues(std::string workPath){

    //Check for running and existing python-environment
    if (this->_pyInstance == nullptr){
        LOGE("FATAL: Python-environment not running!");
        return false;
    }

    //First of all, resume the driver
    if (this->_driverPyModule.execFunction("resume", NULL) != "N"){
        LOGE("Error in resuming driver!");
        return false;
    }

    PyObject* pyQueryArgs = PyTuple_New(3);
    std::string wp;
    std::string pyRet;
    //Then iterate through the values
    for (size_t i = 0; i < this->_values.size(); i++){
        WSValue& curVal = this->_values.at(i);

        wp = workPath + "/" + this->_name + "/" + curVal.name();

        //Create the directories for the wp
        LOGD("Working directory for value " + std::to_string(i) + ": " + wp);
        if (!std::filesystem::create_directories(wp)){
        }

        //First arg(int): globalValueId
        PyTuple_SetItem(pyQueryArgs, 0, Py_BuildValue("i#", curVal.gId()));
        //Second arg(int): localValueId
        PyTuple_SetItem(pyQueryArgs, 1, Py_BuildValue("i#", curVal.lId()));
        //Thirs arg(string): working path for this driver to do its work
        PyTuple_SetItem(pyQueryArgs, 2, Py_BuildValue("s#", wp.c_str(), wp.length()));

        pyRet = this->_driverPyModule.execFunction("getValue", pyQueryArgs);

        LOGI("Return from function call: \"" + pyRet + "\"");

        curVal.value(pyRet[0], pyRet.substr(1, pyRet.length()-1));
    }

    //And then pause the driver again
    if (this->_driverPyModule.execFunction("pause", NULL) != "N"){
        LOGE("Error in pausing driver!");
        return false;
    }

    return true;
}

std::string WSDriver::valueOverview(){
    std::string ret = "WSDriver \"" + this->_name + "\":\n";
    for (auto& i : this->_values){
        ret += "\t" + i.toString() + "\n";
    }
    return ret;
}
