#include "weathersens.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

bool Weathersens::startSyncLoop(){
    FUN();
    this->_runSyncLoop = true;
    this->_t_syncloop = new std::thread(&Weathersens::syncLoop, this);
    return true;
}

void Weathersens::stopSyncLoop(){
    FUN();
    this->_m_runSyncLoop.lock();
    this->_runSyncLoop = false;
    this->_m_runSyncLoop.unlock();
    LOGI("Waiting for sync-thread to  join...");
    while (this->_t_syncloop->joinable())
           this->_t_syncloop->join();
    delete this->_t_syncloop;
    LOGI("Joined!");
}

void Weathersens::syncLoop(){
    FUN();
    this->_m_runSyncLoop.lock();
    while (this->_runSyncLoop){
        this->_m_runSyncLoop.unlock();
        this->callValues();
        sleep(this->_syncTimeout);
        this->_m_runSyncLoop.lock();
    }
    //The output must be flushed on an ending thread
    //so that the rest of the output does not get stopped
    LOGP("Exiting sync-loop...");
    this->_m_runSyncLoop.unlock();
}
