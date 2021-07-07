#include "hndrivers.h"

#include <Python.h>

bool HNDrivers::sync(){
    FUN();

    PyObject* args = PyTuple_New(3);

    for (HNDriver* curDriver : this->_drivers){

        {   //Resume the driver
            if (this->_pyInst->execModFunction(curDriver->name() + ".main", "resume", nullptr) == "E"){
                LOGE("Error resuming driver \"" + curDriver->name() + "\"!");
                continue;
            }
        }

        for (hnvalue_t* curValue : curDriver->getValues()){
            std::string wp = this->_workdir + "/" + curDriver->name() + "/" + curValue->name + "/";
            LOGI(   "Syncing \"" + curDriver->name() + "--" + curValue->name + "\" (gID: " +
                    std::to_string(curValue->gID) + " lID: " + std::to_string(curValue->lID) + " wd: " + wp + ")");

            PyTuple_SetItem(args, 0, Py_BuildValue("i#", curValue->gID));
            PyTuple_SetItem(args, 1, Py_BuildValue("i#", curValue->lID));
            PyTuple_SetItem(args, 2, Py_BuildValue("s#", wp.c_str(), wp.length()));

            std::string ret = this->_pyInst->execModFunction(curDriver->name() + ".main", "getValue", args);

            curValue->datatype = ret[0];
            curValue->value = ret.substr(1, ret.length()-1);
        }

        {   //Pause the driver
            if (this->_pyInst->execModFunction(curDriver->name() + ".main", "pause", nullptr) == "E"){
                LOGE("Error stopping driver \"" + curDriver->name() + "\"!");
            }
        }
    }

    return true;
}
