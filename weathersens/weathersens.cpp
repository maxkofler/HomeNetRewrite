#include "weathersens.h"

Weathersens::Weathersens(std::string wsConfigPath, HomeNet* hn){
    this->_ok = false;
    this->_hn = hn;
    this->_config = new WSConfig(wsConfigPath);
    std::string conf;
    conf = this->_config->getConfig("driverdir");
    if (conf.empty()){
        LOGE("Could not find config for \"driverdir\", Weathersens will not load!");
        return;
    }
    conf = this->_config->getConfig("driverlist");
    if (conf.empty()){
        LOGE("Could not find config for \"driverlist\", Weathersens will not load!");
        return;
    }
}
