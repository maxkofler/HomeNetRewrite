#include "hnhistorydaemon/job.h"
#include "log.h"

Job::Job(job_type type, Args args){
	FUN();

	this->_job_type = type;
	this->_args = args;
}
