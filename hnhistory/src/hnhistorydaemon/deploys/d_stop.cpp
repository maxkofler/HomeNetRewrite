#include "hnhistorydaemon.h"
#include "hnhistorydaemon/jobs/stop.h"
#include "log.h"

bool HNHistoryDaemon::d_stop(){
	FUN();

	this->lock_waiting("stop");

	{//Deploy the new job
		Job* newJob = new Jobs::Stop(this);
		this->_waiting_jobs.push(newJob);
	}

	this->_m_waiting_jobs.unlock();

	//Release the daemon so it can maybe immediately start this job
	this->release();

	return true;
}
