#include "hndriver.h"

HNDriver::HNDriver(std::string name, size_t id){
    FUN();

    this->_name = name;
    this->_id = id;
}

HNDriver::~HNDriver(){
    FUN();
}
