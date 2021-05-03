#include "weathersens.h"

Weathersens::Weathersens(std::string wsConfigPath, HomeNet* hn){
    FUN();
    this->_runlevel = -1;
    this->_hn = hn;
    this->_config = new WSConfig(wsConfigPath);
    std::string conf;
    conf = this->_config->getConfig("driverdir");
    if (conf.empty()){
        LOGE("Could not find config for \"driverdir\", Weathersens will not load!");
        return;
    }
    this->_driverDir = conf;
    conf = this->_config->getConfig("driverlist");
    if (conf.empty()){
        LOGE("Could not find config for \"driverlist\", Weathersens will not load!");
        return;
    }
    this->_driverList = conf;
    this->_runlevel = 1;
    LOGD("Weathersens reached runlevel 1!");
}

void Weathersens::loadDrivers(){
    //parseDriverList();
}
