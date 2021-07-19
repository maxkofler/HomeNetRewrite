#include "homenet.h"

#include "configQueryException.h"

void HomeNet::start(){
    FUN();

    try{
        std::string fStr = "Starting HomeNet: ";

        {
            LOGI(fStr + "Parsing config");
            if (!this->_config->parse("/etc/homenet/hnconfig.conf")){
                LOGE(fStr + "Error in parsing config!");
                emit stop();
                return;
            }

            LOGI(fStr + "Getting configs");

            this->_time_sync = stoi(this->_config->getConfig("synctime", true).back());
        }

        {
            LOGI(fStr + "Starting Python");
            this->_python->startPython(true);
        }

        {
            LOGI(fStr + "Initializing history module");

            if (!this->_history->init(*this->_config)){
                LOGE(fStr + "Error in initializing history module!");
                emit stop();
                return;
            }
        }

        {
            LOGI(fStr + "Initializing drivers");

            if (!this->_drivers->init(*this->_config, this->_python, this->_history)){
                LOGE(fStr + "Error in initializing drivers!");
                emit stop();
                return;
            }

            LOGI(fStr + "Loading drivers");
            if (!this->_drivers->loadDrivers()){
                LOGE(fStr + "Error in loading drivers!");
                emit stop();
                return;
            }
        }

        {
            LOGI(fStr + "Starting networking module");

            if (!this->_networking->start(*this->_config, this->_drivers)){
                LOGE(fStr + "Error in starting networking module!");
                emit stop();
                return;
            }
        }

        {
            LOGI(fStr + "Starting syncloop with " + std::to_string(this->_time_sync) + " seconds");

            this->_timerSync = new QTimer(this);
            connect(this->_timerSync, &QTimer::timeout, this, QOverload<>::of(&HomeNet::sync));
            this->_timerSync->start(this->_time_sync*1000);
        }
    }

    catch(ConfigQueryException e){
        LOGE("Could not find a critical configuration: " + e.key);
        emit stop();
        return;
    }

    catch(...){
        LOGE("A critical error raised during execution!");
        emit stop();
        return;
    }
}
