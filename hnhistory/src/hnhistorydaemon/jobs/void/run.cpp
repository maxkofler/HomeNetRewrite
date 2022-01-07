#include "hnhistorydaemon/jobs/void.h"
#include "log.h"



void Jobs::Void::run(){
	FUN();

	this->_is_running = true;

	LOGD("Void job: Waiting for " + std::to_string(this->_waittime));
	QThread::msleep(this->_waittime);
	LOGD("Void job: Finished waiting");
	
	this->finished();
}
