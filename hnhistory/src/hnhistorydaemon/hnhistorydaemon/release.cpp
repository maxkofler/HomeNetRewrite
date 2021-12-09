#include "hnhistorydaemon.h"

void HNHistoryDaemon::release(){
	FUN();

	if (!this->_m_reserved.try_lock()){
		LOGD("Waiting for history daemon to become ready...");
		this->_m_reserved.lock();
	}

	LOGD("Releasing history daemon...");
	this->_m_eventLoop.unlock();
}
