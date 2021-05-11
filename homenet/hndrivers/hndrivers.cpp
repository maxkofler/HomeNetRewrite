#include "hndrivers.h"

HNDrivers::HNDrivers(){
    FUN();

    this->_runlevel = -1;
}

HNDrivers::~HNDrivers(){
    if (this->_runlevel >= 0)
        delete this->_driverListParser;
    this->_runlevel = -1;
}

bool HNDrivers::start(HNConfig* config){
    //Parsing configs
    {
        this->_driverListPath = config->getConfig("driverlist");
        this->_driversPath = config->getConfig("driverdir");
        std::string syncTimeStr = config->getConfig("synctime");

        if (this->_driverListPath.empty() || this->_driversPath.empty() || syncTimeStr.empty()){
            LOGE("Can not start HNDrivers: one or more configs not provided!");
            return false;
        }

        this->_syncTime = std::stoi(syncTimeStr);
        _runlevel = 0;
    }

    this->_driverListParser = new Parser();
    this->_driverListParser->parseFile(this->_driverListPath);
    LOGI("Fetching driver data...");
    this->p_fetchDrivers();

    return true;
}
