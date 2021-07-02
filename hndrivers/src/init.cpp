#include "hndrivers.h"

#include <fstream>

bool HNDrivers::init(HNConfig& config, HNPython* pyInst){
    FUN();

    this->_rl_initialized = false;

    std::string initDRstr = "Initializing HNDrivers: ";

    {   //Parse configs
        LOGI(initDRstr + "fetching configs");
        this->_driverlistPath = config.getConfig("driverlist").back();
        this->_driversPath = config.getConfig("driverdir").back();
        this->_workdir = config.getConfig("workdir").back();
    }    

    {   //Init the driverlist parser
        LOGI(initDRstr + "parsing driverlist");

        HNParser _driverlistParser;

        std::ifstream driverlist;
        driverlist.open(this->_driverlistPath);

        if (!driverlist.is_open() || driverlist.bad()){
            LOGE(initDRstr + "Error in opening driverlist file (not found)");
            driverlist.close();
            return false;
        }

        if (_driverlistParser.parseStream(driverlist) <= 0){
            LOGE(initDRstr + "Error in parsing driverlist file (empty?)");
            driverlist.close();
            return false;
        }

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
