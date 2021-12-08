#include "hnhistorydaemon/job.h"
#include "log.h"

void Job::finished(){
	FUN();

	this->_is_running = false;
	emit this->jobFinished(this->_id);
}
