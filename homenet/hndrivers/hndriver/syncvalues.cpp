#include "hndriver.h"

#include <filesystem>

bool HNDriver::syncValues(std::string workDir, HNHistory& history){
    FUN();
    if (!this->p_resumeDriver()){
        LOGE("Error resuming driver, not calling values!");
        return false;
    }

    std::string buf;
    for (auto& i : this->_values){
        buf = this->p_callValue(i, workDir);
        i.setValueFromPython(buf[0], buf.substr(1, buf.size()-1));
        history.createValueEntry(this->_name, i);
    }

    this->p_pauseDriver();

    return true;
}

bool HNDriver::p_resumeDriver(){
    FUN();
    if (!this->_moduleLoaded){
        LOGE("Python module is not loaded!");
        return false;
    }
    if (this->_pyModule.execFunction("resume", NULL) != "N"){
        LOGE("Error in resuming this driver!");
        return false;
    }

    return true;
}

bool HNDriver::p_pauseDriver(){
    FUN();
    if (!this->_moduleLoaded){
        LOGE("Python module is not loaded!");
        return false;
    }
    if (this->_pyModule.execFunction("pause", NULL) != "N"){
        LOGE("Error in pausing this driver!");
        return false;
    }

    return true;
}

std::string HNDriver::p_callValue(HNValue &v, std::string workDir){
    FUN();
    if (!this->_moduleLoaded){
        LOGE("Python module is not loaded!");
        return std::string("");
    }

    std::string wp = workDir + "/" + this->_name + "/" + v.name();

    LOGD("Working directory for value " + v.name() + ": " + wp);
    if (!std::filesystem::create_directories(wp)){
    }

    PyObject* pyArgs = PyTuple_New(3);

    PyTuple_SetItem(pyArgs, 0, Py_BuildValue("i#", v.gId()));
    PyTuple_SetItem(pyArgs, 1, Py_BuildValue("i#", v.lId()));
    PyTuple_SetItem(pyArgs, 2, Py_BuildValue("s#", wp.c_str(), wp.length()));

    auto ret = this->_pyModule.execFunction("getValue", pyArgs);

    //Delete the tuple???
    Py_DecRef(pyArgs);

    return ret;
}
