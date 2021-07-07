#include "hndriver.h"

bool HNDriver::addValue(hnvalue_t* newValue){
    FUN();
    
    newValue->drivername = this->_name;
    this->_values.push_back(newValue);

    return true;
}
