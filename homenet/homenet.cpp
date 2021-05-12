#include "homenet.h"

HomeNet::HomeNet(std::string configPath){
    this->_config = new HNConfig(configPath);
    this->_py = new HNPython();
    this->_drivers = new HNDrivers();
    this->_drivers->start(this->_config, this->_py);
}

HomeNet::~HomeNet(){
    delete this->_config;
    delete this->_py;
    delete this->_drivers;
}

bool HomeNet::sync(){
    return this->_drivers->sync();
}

std::string HomeNet::getOverview(){
    return this->_drivers->getOverview();
}
