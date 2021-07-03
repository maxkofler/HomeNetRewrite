#include "hndrivers.h"

#include <fstream>

bool HNDrivers::init(HNConfig& config, HNPython* pyInst){
    FUN();

    this->_rl_initialized = false;

    std::string initDRstr = "Initializing HNDrivers: ";

    {   //Parse configs
        LOGI(initDRstr + "Fetching configs");
        this->_driverlistPath = config.getConfig("driverlist").back();
        this->_driversPath = config.getConfig("driverdir").back();
        this->_workdir = config.getConfig("workdir").back();
    }    

    {   //Init the driverlist parser
        LOGI(initDRstr + "Preparsing driverlist");

        std::ifstream driverlist;
        driverlist.open(this->_driverlistPath);

        if (!driverlist.is_open() || driverlist.bad()){
            LOGE(initDRstr + "Error in opening driverlist file (not found)");
            driverlist.close();
            return false;
        }

        if (this->_driverlistParser.parseStream(driverlist, true) <= 0){
            LOGE(initDRstr + "Error in preparsing driverlist file (empty?)");
            driverlist.close();
            return false;
        }

        LOGI("Preparsed " + std::to_string(this->_driverlistParser.size()) + " lines!");

        driverlist.close();
    }

    {   //Check Python instance
        LOGI(initDRstr + "Checking for HNPython instance");
        if (pyInst == nullptr){
            LOGE(initDRstr + "Error in getting Python instance: not existing");
            return false;
        }

        this->_pyInst = pyInst;
    }

    this->_rl_initialized = true;
    return true;
}
