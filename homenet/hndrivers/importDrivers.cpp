#include "hndrivers.h"

bool HNDrivers::p_importDrivers(){

    //Check for pointers...
    if (this->_python == nullptr){
        LOGE("Python pointer is not valid!");
        return false;
    }
    if (this->_runlevel < 1){
        LOGE("Runlevel to low!");
        return false;
    }

    this->_python->addPythonPath(this->_driversPath);

    for (auto& i : this->_drivers){
        auto mod = this->_python->loadModule(i.getName() + ".main");
        if (mod.imported())
            i.setPyModule(mod);
        else{
            LOGE("Error in importing module. Ignoring this driver!");
            continue;
        }
    }

    return true;
}
