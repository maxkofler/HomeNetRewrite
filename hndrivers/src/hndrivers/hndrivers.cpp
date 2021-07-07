#include "hndrivers.h"

HNDrivers::HNDrivers(){
    FUN();

    this->_rl_initialized = false;
    this->_rl_driversloaded = false;
    this->_nextVId = 0;
}

HNDrivers::~HNDrivers(){
    FUN();
}
