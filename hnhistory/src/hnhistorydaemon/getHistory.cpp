#include "hnhistorydaemon.h"
#include "hnhistorydaemon/jobs/getHistory.h"
#include "log.h"

bool HNHistoryDaemon::getHistory(hnvalue_t value){
	FUN();

	{//Reserve the daemon to deploy a job
		if (!this->_m_reserved.try_lock()){
			LOGD("Waiting for permission to deploy job...");
			this->_m_reserved.lock();
			LOGD("Receied permission, proceeding...");
		}
	}

	{
		//TODO: implement job creation
	}

	return true;
}
