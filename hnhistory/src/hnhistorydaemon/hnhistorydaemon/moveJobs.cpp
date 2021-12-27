#include "hnhistorydaemon.h"
#include "log.h"

bool HNHistoryDaemon::moveJobs(){
	FUN();

	std::string fStr = "History daemon: ";

	LOGD(fStr + 	"Jobs waiting: " + std::to_string(this->_waiting_jobs.size()) + ", " +
					"Jobs running: " + std::to_string(this->_running_jobs.size()));

	{
		bool run = true;
		while(run){

			if (this->_waiting_jobs.size() <= 0){
				LOGD(fStr + "No jobs waiting for deployment");
				run = false;
				continue;
			}

			if (this->_running_jobs.size() >= this->_maxThreads){
				LOGD(fStr + "Thread-budget is maxed, waiting for jobs to finish to deploy next job");
				run = false;
				continue;
			}

			this->lock_waiting("daemon");
			{//Move the job from waiting to running and start it
				LOGD(fStr + "Deploying a new job...");
				Job* curJob = this->_waiting_jobs.front();
				this->_waiting_jobs.pop();
				this->connectJob(curJob);
				this->addRunningJob(curJob);
				curJob->start();
				LOGD(fStr + "Finished deploying the new job");
			}

			this->_m_waiting_jobs.unlock();

		}

	}

	return true;
}
