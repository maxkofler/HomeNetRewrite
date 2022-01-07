#include "hnhistorydaemon.h"
#include "hnhistorydaemon/jobs/void.h"
#include "log.h"

bool HNHistoryDaemon::d_void(int time){
	FUN();

	this->lock_waiting("void");

	{//Deploy the new job
		Job* newJob = new Jobs::Void(this, time);
		this->_waiting_jobs.push(newJob);
	}

	this->_m_waiting_jobs.unlock();

	//Release the daemon so it can maybe immediately start this job
	this->release();

	return true;
}
