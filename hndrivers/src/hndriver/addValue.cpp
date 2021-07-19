#include "hndriver.h"

bool HNDriver::addValue(hnvalue_t* newValue){
    FUN();

    this->_values.push_back(newValue);

    return true;
}
