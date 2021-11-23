#include "homenet.h"

void HomeNet::sync(){
    FUN();

    LOGI("Syncing values...");

    try{
        this->_drivers->sync();
    }catch(...){
        LOGE("Fatal exception during syncing!");
    }

	this->_historyDaemon->release();
}
