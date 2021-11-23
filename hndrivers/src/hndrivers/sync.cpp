#include "hndrivers.h"

#include <filesystem>

bool HNDrivers::sync(){
    FUN();

    //PyObject* args = PyTuple_New(3);
    PyArgs args(3);

    for (HNDriver* curDriver : this->_drivers){

        {   //Resume the driver
            if (this->_pyInst->execModFunction(curDriver->name() + ".main", "resume", nullptr) == "E"){
                LOGE("Error resuming driver \"" + curDriver->name() + "\"!");
                continue;
            }
        }

        for (hnvalue_t* curValue : curDriver->getValues()){
            std::string wp = this->_workdir + "/" + curDriver->name() + "/" + curValue->name + "/";

            //Create the working path
            std::filesystem::create_directories(wp);

            LOGI(   "Syncing \"" + curDriver->name() + "--" + curValue->name + "\" (gID: " +
                    std::to_string(curValue->gID) + " lID: " + std::to_string(curValue->lID) + " wd: " + wp + ")");

            args.setItem(0, "i#", curValue->gID);
            args.setItem(1, "i#", curValue->lID);
            args.setItem(2, "s#", wp.c_str(), wp.length());

            std::string ret = this->_pyInst->execModFunction(curDriver->name() + ".main", "getValue", args.getArgv());

            curValue->datatype = ret[0];
            curValue->value = ret.substr(1, ret.length()-1);

            if (!this->_history->append(*curValue)){
                LOGW("Failed to append value to history!");
            }
        }

        {   //Pause the driver
            if (this->_pyInst->execModFunction(curDriver->name() + ".main", "pause", nullptr) == "E"){
                LOGE("Error stopping driver \"" + curDriver->name() + "\"!");
            }
        }
    }

    return true;
}
