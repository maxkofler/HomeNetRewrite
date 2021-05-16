#include "homenet.h"

void HomeNet::p_syncLoop(){
    FUN();
    LOGD("Locking syncloop mutex...");
    this->_m_runSyncLoop.lock();
    while(this->_runSyncLoop){
        LOGD("Unlocking syncloop mutex in loop...");
        this->_m_runSyncLoop.unlock();

        this->sync();

        LOGI("Value overview:\n" + this->getOverview());

        LOGI("Sleeping for " + std::to_string(this->_syncloop_sleeptime) + " seconds...");
        sleep(this->_syncloop_sleeptime);

        LOGD("Locking syncloop mutex...");
        this->_m_runSyncLoop.lock();
    }
    LOGD("Unlocking syncloop mutex at end of loop...");
    this->_m_runSyncLoop.unlock();
}

bool HomeNet::startSyncLoop(){
    FUN();
    bool ret = false;
    this->_m_runSyncLoop.lock();

    if (this->_runSyncLoop){
        LOGE("Syncloop seems to be already running!");
    }else{
        this->_runSyncLoop = true;
        this->_t_syncLoop = new std::thread(&HomeNet::p_syncLoop, this);
        ret = true;
    }

    this->_m_runSyncLoop.unlock();

    return ret;
}

bool HomeNet::stopSyncLoop(){
    FUN();
    bool ret = false;
    this->_m_runSyncLoop.lock();

    if (this->_runSyncLoop){
        this->_runSyncLoop = false;
        this->_m_runSyncLoop.unlock();

        LOGI("Waiting for syncloop thread to join...");

        this->_t_syncLoop->join();

        LOGI("Syncloop thread joined!");

        delete this->_t_syncLoop;

        ret = true;

    }else{
        this->_m_runSyncLoop.unlock();
        LOGE("Syncloop is not running, so it can't be stopped!");
    }

    return ret;
}

bool HomeNet::isSyncLoopRunning(){
    FUN();
    bool ret;
    this->_m_runSyncLoop.lock();

    ret = this->_runSyncLoop;

    this->_m_runSyncLoop.unlock();

    return ret;
}
