#include "hnhistorydaemon.h"
#include "log.h"

bool HNHistoryDaemon::addRunningJob(Job *job){
	FUN();

	if (this->_running_jobs.size() >= this->_maxThreads){
		LOGD("Thread budget is already maxed");
		return false;
	}

	this->_running_jobs[this->_nextJobID] = job;
	job->_id = this->_nextJobID;

	this->_nextJobID++;

	return true;
}
