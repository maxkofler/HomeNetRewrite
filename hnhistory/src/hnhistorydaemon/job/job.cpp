#include "hnhistorydaemon/job.h"
#include "log.h"

Job::Job(job_type expected, job_type actual, Args args){
	FUN();

	if (actual != expected){
		JobTypeMissmatchException ex;
		throw ex;
	}

	this->_job_type = actual;
	this->_args = args;
}
