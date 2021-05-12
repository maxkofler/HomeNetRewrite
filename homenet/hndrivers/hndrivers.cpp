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

bool HNDrivers::start(HNConfig* config, HNPython* pyInst){
    //Parsing configs
    {
        this->_driverListPath = config->getConfig("driverlist");
        this->_driversPath = config->getConfig("driverdir");
        this->_workDir = config->getConfig("workdir");
        std::string syncTimeStr = config->getConfig("synctime");

        if (this->_driverListPath.empty() || this->_driversPath.empty() || this->_workDir.empty() || syncTimeStr.empty()){
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
    this->_runlevel = 1;

    this->_python = pyInst;
    if (!this->p_importDrivers()){
        LOGE("Not imported drivers!");
        return false;
    }

    return true;
}

bool HNDrivers::sync(){
    bool ret = true;
    for (auto& i : this->_drivers){
        ret = ret && i.syncValues(this->_workDir);
    }
    return ret;
}

std::string HNDrivers::getOverview(){
    std::string ret = "";
    for (auto& i : this->_drivers){
        ret += i.getOverview();
    }
    return ret;
}
