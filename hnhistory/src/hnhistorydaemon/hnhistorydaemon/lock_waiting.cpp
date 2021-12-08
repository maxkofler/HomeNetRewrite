#include "hnhistorydaemon.h"
#include "log.h"

void HNHistoryDaemon::lock_waiting(std::string context){
	FUN();

	LOGD("Getting permission to access waiting jobs (" + context + ")");

	if (!this->_m_waiting_jobs.try_lock()){
		LOGD("History daemon: Waiting for permission to access waiting jobs (" + context + ")...");
		this->_m_waiting_jobs.lock();
		LOGD("History daemon: Got permission to access waiting jobs (" + context + ")");
	}
}
