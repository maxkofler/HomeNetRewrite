#include "hnhistorydaemon.h"

bool HNHistoryDaemon::stop(){
	FUN();
	std::string fStr = "Stopping history daemon: ";
	LOGI(fStr + "Stopping...");

	{//Delete all mutexes
		LOGD(fStr + "Deleting mutexes...");
		std::map<std::string, std::mutex*>::iterator it = this->_file_mutexes.begin();
		while(it != this->_file_mutexes.end()){
			delete it->second;
			it++;
		}
		this->_file_mutexes.clear();
	}

	if (!this->_run){
		LOGD("Failed to stop history daemon: it was not running");
		return false;
	}

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
