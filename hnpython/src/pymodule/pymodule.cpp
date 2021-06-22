#include "pymodule.h"

PyModule::PyModule(){
    FUN();
    this->_is_loaded = false;
}

PyModule::~PyModule(){
    FUN();
    this->_is_loaded = false;
}
