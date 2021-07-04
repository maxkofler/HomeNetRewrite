#include "hndrivers.h"

bool HNDrivers::loadDrivers(){
    FUN();

    this->_rl_driversloaded = false;
    std::string fStr = "Loading HNDrivers: ";

    {   //Check for runlevel
        LOGI(fStr + "Checking for correct runlevel of HNDrivers");

        if (!this->_rl_initialized){
            LOGE(fStr + "Runlevel is insufficient to load drivers!");
            return false;
        }
    }

    {   //Check if HNPython is running
        LOGI(fStr + "Checking if HNPython is running");

        if (!this->_pyInst->isRunning()){
            LOGE(fStr + "Python instance is NOT RUNNING!");
            return false;
        }
    }

    {   //Parse the driverlist
        LOGI(fStr + "Parsing driverlist");

        if (!p_parseDriverlist()){
            LOGE(fStr + "Error in parsing driverlist!");
            return false;
        }
    }

    {   //Import drivers
        LOGI(fStr + "Importing drivers");

        if (!p_importDrivers()){
            LOGE(fStr + "Error in importing drivers!");
            return false;
        }
    }

    this->_rl_driversloaded = true;
    return true;
}