#include "hnhistorydaemon.h"
#include "hnhistorydaemon/jobs/getHistory.h"
#include "log.h"

bool HNHistoryDaemon::getHistory(hnvalue_t* value){
	FUN();

	{//Reserve the daemon to deploy a job
		if (!this->_m_reserved.try_lock()){
			LOGD("Waiting for permission to deploy job...");
			this->_m_reserved.lock();
			LOGD("Receied permission, proceeding...");
		}
	}

	{//Deploy the new job
		Args args;
		args.addArg((void*)value);
		Job* newJob = new Jobs::GetHistory(args);
		this->_waiting_jobs.push(newJob);
	}

	//Release the daemon so it can maybe immediately start this job
	this->release();

	return true;
}
