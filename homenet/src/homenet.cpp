#include "homenet.h"

HomeNet::~HomeNet(){
    FUN();
    
    delete this->_config;
    delete this->_python;
    delete this->_drivers;
}