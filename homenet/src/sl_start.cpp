#include "homenet.h"

void HomeNet::start(){
    FUN();

    std::string fStr = "Starting HomeNet: ";

    {
        LOGI(fStr + "Parsing config");
        if (!this->_config->parse("/etc/homenet/hnconfig.conf")){
            LOGE(fStr + "Error in parsing config!");
            goto STOP;
        }
    }

    {
        LOGI(fStr + "Starting Python");
        this->_python->startPython(true);
    }

    {
        LOGI(fStr + "Initializing drivers");

        if (!this->_drivers->init(*this->_config, this->_python)){
            LOGE(fStr + "Error in initializing drivers!");
            goto STOP;
        }

        LOGI(fStr + "Loading drivers");
        if (!this->_drivers->loadDrivers()){
            LOGE(fStr + "Error in loading drivers!");
            goto STOP;
        }
    }

STOP:
    emit stop();
}
