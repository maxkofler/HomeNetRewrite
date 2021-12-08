#include "hnhistorydaemon/job.h"
#include "log.h"

Job::Job(HNHistoryDaemon* daemon, job_type type){
	FUN();

	this->_job_type = type;
	this->_historyDaemon = daemon;
}
