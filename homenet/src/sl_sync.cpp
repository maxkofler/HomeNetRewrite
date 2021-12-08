#include "homenet.h"

void HomeNet::sync(){
	FUN();

	LOGI("Syncing values...");

	try{
		this->_drivers->sync();
		hnvalue_t value;
		this->_historyDaemon->d_getHistory(value);
		this->_historyDaemon->d_cleanHistory("/etc/homenet/history/WSxUMBDriver/Temperatur.hnhist");
	}catch(...){
		LOGE("Fatal exception during syncing!");
	}
}
