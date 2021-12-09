#include "hnhistorydaemon.h"
#include "hnhistorydaemon/jobs/appendHistory.h"
#include "log.h"

bool HNHistoryDaemon::d_appendHistory(hnvalue_t value){
	FUN();

	this->lock_waiting("appendHistory");

	{//Deploy the new job
		Job* newJob = new Jobs::AppendHistory(this, value);
		this->_waiting_jobs.push(newJob);
	}

	this->_m_waiting_jobs.unlock();

	//Release the daemon so it can maybe immediately start this job
	this->release();

	return true;
}
