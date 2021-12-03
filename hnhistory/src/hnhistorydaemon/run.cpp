#include "hnhistorydaemon.h"

void HNHistoryDaemon::run(){
	FUN();

	std::string fStr = "History daemon: ";

	LOGI("Starting HNHistory Daemon...");

	this->_run = true;

	//Lock the mutex for now, there is nothing to do at this stage
	this->_m_eventLoop.try_lock();

	while (this->_run){
		LOGD(fStr + "Going to sleep");
		this->_m_eventLoop.lock();
		LOGD(fStr + "Pending operation, awaking from sleep");
		this->_m_reserved.unlock();
	}

	LOGI(fStr + "Exited from event loop");
}
