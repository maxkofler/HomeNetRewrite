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
		this->_curJob_type = JOB_GET_HISTORY;
		Args args;
		this->_curJob_args = args;
	}

	//Release the daemon to do deploy this job
	this->release();

	return true;
}
