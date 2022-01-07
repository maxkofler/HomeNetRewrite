#include "hnhistorydaemon.h"

void HNHistoryDaemon::release(){
	FUN();

	if (!this->isRunning()){
		LOGE("History daemon release: Thread is not running!");
		return;
	}

	if (!this->_m_eventLoop.try_lock()){
		LOGD("History daemon release: Deamon already sleeping, releasing now");
	} else if (!this->_m_reserved.try_lock()){
		LOGD("History daemon release: Waiting for history daemon to become ready...");
		this->_m_reserved.lock();
		this->_m_reserved.unlock();
	}
	
	this->_m_eventLoop.unlock();
}
