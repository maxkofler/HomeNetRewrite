#include "hnhistorydaemon.h"

#include "hnhistorydaemon/allJobs.h"

void HNHistoryDaemon::run(){
	FUN();

	std::string fStr = "History daemon: ";

	LOGI("Starting HNHistory Daemon...");

	this->_run = true;

	//Lock the mutex for now, there is nothing to do at this stage
	this->_m_eventLoop.try_lock();

	while (this->_run){
		LOGD(fStr + "Going to sleep");
		this->_m_eventLoop.lock();
		LOGD(fStr + "Pending operation, awaking from sleep");
		this->_m_reserved.unlock();

		if (!this->_run)
			continue;

		if (this->_waiting_jobs.size() <= 0){
			LOGD(fStr + "No jobs waiting for deployment");
			continue;
		}

		if (this->_running_jobs.size() >= this->_maxThreads){
			LOGD(fStr + "Thread-budget is maxed, waiting for jobs to finish to deploy next job");
			continue;
		}

		{//Move the job from waiting to running and start it
			LOGD(fStr + "Deploying a new job...");
			Job* curJob = this->_waiting_jobs.front();
			this->_waiting_jobs.pop();
			this->_running_jobs.push(curJob);
			curJob->start();
			LOGD(fStr + "Finished deploying the new job");
		}
	}

	LOGI(fStr + "Stopping history daemon");

	{
		LOGI(fStr + "Cleaning up all current jobs...");

		{//Remove all waiting jobs
			size_t killed = 0;
			while(!this->_waiting_jobs.empty()){
				Job* curJob = this->_waiting_jobs.front();
				this->_waiting_jobs.pop();
				delete curJob;
				killed++;
			}
			LOGI(fStr + std::to_string(killed) + " jobs were waiting");
		}

		{//Wait for all jobs to join
			size_t killed = 0;
			while(!this->_running_jobs.empty()){
				LOGD(fStr + "Waiting for one of " + std::to_string(this->_running_jobs.size()) + 
							" running jobs to join...");
				this->_m_eventLoop.lock();
				LOGD(fStr + "One Job joined");
			}
			LOGI(fStr + std::to_string(killed) + " running jobs joined");
		}
	}

	LOGI(fStr + "Exited from event loop");
}
