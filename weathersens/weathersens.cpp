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
    this->_hn->_py->addPythonPath(this->_driverDir);


    conf = this->_config->getConfig("driverlist");
    if (conf.empty()){
        LOGE("Could not find config for \"driverlist\", Weathersens will not load!");
        return;
    }
    this->_driverListPath = conf;
    this->_runlevel = 1;
    LOGD("Weathersens reached runlevel 1!");
    this->_driverlist = new WSDriverList(this->_driverListPath);
    LOGD("Weathersens reached runlevel 2!");
    this->_driverlist->importPythonDrivers(this->_hn->_py);
}

Weathersens::~Weathersens(){
    delete this->_config;
    delete this->_driverlist;
}
