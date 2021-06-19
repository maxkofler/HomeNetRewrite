#include "homenet.h"

HomeNet::HomeNet(std::string configPath){
    FUN();
    this->_runSyncLoop = false;
    this->_runlevel = -1;
    this->_config = new HNConfig(configPath);
    this->_py = new HNPython();
    this->_drivers = new HNDrivers();
    this->_drivers->start(this->_config, this->_py);
    this->_runlevel = 0;

    //Parse the neccesary configs if these fail, homenet will quit
    {

        std::string confHistoryDir = this->_config->getConfig("historydir");
        std::string confSyncLoopSleep = this->_config->getConfig("synctime");


        if (confHistoryDir.empty() || confSyncLoopSleep.empty()){
            LOGE("Could not find one or more NECESSARY configs!");
            this->p_cleanPointers();
            exit(-1);
        }

        this->_history = new HNHistory(confHistoryDir);

        this->_syncloop_sleeptime = std::stoi(confSyncLoopSleep);

        this->_runlevel = 1;
    }
    {
        this->_networking = new HNNetworking();
        this->_networking->startListening(8080);
        this->_runlevel = 2;
    }
}

HomeNet::~HomeNet(){
    FUN();
    this->stopSyncLoop();
    this->p_cleanPointers();
}

bool HomeNet::sync(){
    FUN();
    bool ret;
    LOGD("Locking syncing mutex...");
    this->_m_syncing.lock();
    ret =  this->_drivers->sync(*this->_history);
    LOGD("Unlocking syncing mutex...");
    this->_m_syncing.unlock();
    emit synced();
    return ret;
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
        delete this->_networking;
    }

    if (this->_runlevel >= 1){
        delete this->_history;
    }
}
