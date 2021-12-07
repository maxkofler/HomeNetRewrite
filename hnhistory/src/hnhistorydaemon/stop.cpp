#include "hnhistorydaemon.h"

bool HNHistoryDaemon::stop(){
	FUN();

	if (!this->_run){
		LOGD("Failed to stop history daemon: it was not running");
		return false;
	}

	std::string fStr = "Stopping history daemon: ";
	LOGI(fStr + "Stopping...");

	{//Let the event loop finish
		LOGI(fStr + "Releasing event loop for finishing");
		this->_run = false;
		this->release();
		
		LOGI(fStr + "Waiting for event loop to finish...");
		this->wait();
		LOGI(fStr + "Event loop finished");
	}

	return true;
}
