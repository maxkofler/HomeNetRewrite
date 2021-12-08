#include "homenet.h"

void HomeNet::sync(){
	FUN();

	LOGI("Syncing values...");

	try{
		this->_drivers->sync();
		hnvalue_t value;
		this->_historyDaemon->getHistory(&value);
	}catch(...){
		LOGE("Fatal exception during syncing!");
	}

	this->_historyDaemon->release();
}
