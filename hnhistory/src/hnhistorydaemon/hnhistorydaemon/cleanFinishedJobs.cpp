#include "hnhistorydaemon.h"
#include "log.h"

bool HNHistoryDaemon::cleanFinishedJobs(){
	FUN();

	if (!this->_m_running_jobs.try_lock()){
		LOGD("History daemon: Waiting for permission to running jobs...");
		this->_m_running_jobs.lock();
	}

	std::map<size_t, Job*>::iterator it = this->_running_jobs.begin();
	bool ret = false;

	{//Iterate over all jobs and delete them if necessary
		size_t curID;
		Job* curJob;

		LOGD(	"History daemon: Checking for " + std::to_string(this->_running_jobs.size()) +
				" cleanable jobs...");

		//Vector containing all ids of cleanable jobs
		std::vector<size_t> cleanable_ids;

		while (it != this->_running_jobs.end()){
			curID = it->first;
			curJob = it->second;

			//Collect cleanable jobs in a vector
			if (!curJob->isRunning()){
				LOGD("History daemon: Waiting for finished job to join...");
				curJob->wait();
				cleanable_ids.push_back(curID);
			}

			it++;
		}

		//Delete the collected jobs and remove them from the map
		for (size_t curID : cleanable_ids){
			LOGD("History daemon: Removing job with id " + std::to_string(curID));
			curJob = this->_running_jobs[curID];
			this->_running_jobs.erase(curID);
			delete curJob;
		}
	}

	this->_m_running_jobs.unlock();

	return ret;
}
