#include "hnhistorydaemon.h"

#include "hnhistorydaemon/allJobs.h"

void HNHistoryDaemon::run(){
	FUN();

	std::string fStr = "History daemon loop: ";

	LOGI("Starting HNHistory Daemon...");
	this->_m_reserved.try_lock();
	this->_m_eventLoop.try_lock();

	this->_run = true;

	{//This is the main execution loop
		while (this->_run){
			this->_m_eventLoop.try_lock();
			this->_m_reserved.unlock();
			this->_m_eventLoop.lock();
			this->_m_reserved.lock();
			LOGD(fStr + "Becoming active to process event");

			if (!this->_run)
				continue;

			bool result = true;
			result &= this->cleanFinishedJobs();
			result &= this->moveJobs();
		}
	}

	LOGI(fStr + "Stopping history daemon");
	this->cleanFinishedJobs();

	{//Clean up all jobs and quit everything nicely
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
				this->cleanFinishedJobs();
			}
			LOGI(fStr + std::to_string(killed) + " running jobs joined");
		}
	}

	LOGI(fStr + "Exited from event loop");
	emit finished();
}
