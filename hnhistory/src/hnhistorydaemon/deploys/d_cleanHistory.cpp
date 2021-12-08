#include "hnhistorydaemon.h"
#include "hnhistorydaemon/jobs/cleanHistory.h"
#include "log.h"

bool HNHistoryDaemon::d_cleanHistory(std::string path){
	FUN();

	this->lock_waiting("cleanHistory");

	{//Deploy the new job
		Job* newJob = new Jobs::CleanHistory(this, path);
		this->_waiting_jobs.push(newJob);
	}

	this->_m_waiting_jobs.unlock();

	//Release the daemon so it can maybe immediately start this job
	this->release();

	return true;
}
