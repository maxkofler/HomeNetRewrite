#include "homenet.h"

HomeNet::HomeNet(std::string configPath){
    FUN();
    this->_runlevel = -1;
    this->_config = new HNConfig(configPath);
    this->_py = new HNPython();
    this->_drivers = new HNDrivers();
    this->_drivers->start(this->_config, this->_py);
    this->_runlevel = 0;

    //Parse the neccesary configs if these fail, homenet will quit
    {
        std::string conf;

        conf = this->_config->getConfig("historydir");

        if (conf.empty()){
            LOGE("Could not find one or more NECESSARY configs!");
            this->p_cleanPointers();
            exit(-1);
        }

        this->_history = new HNHistory(conf);

        this->_runlevel = 1;
    }
}

HomeNet::~HomeNet(){
    FUN();
    this->p_cleanPointers();
}

bool HomeNet::sync(){
    FUN();
    return this->_drivers->sync(*this->_history);
}

std::string HomeNet::getOverview(){
    FUN();
    return this->_drivers->getOverview();
}


void HomeNet::p_cleanPointers(){
    FUN();
    LOGD("Deleting objects...");
    if (this->_runlevel >= 0){
        delete this->_config;
        delete this->_py;
        delete this->_drivers;
    }

    if (this->_runlevel >= 1){
        delete this->_history;
    }
}
