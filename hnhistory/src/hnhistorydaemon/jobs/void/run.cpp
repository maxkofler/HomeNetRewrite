#include "hnhistorydaemon/jobs/void.h"
#include "log.h"



void Jobs::Void::run(){
	FUN();

	QThread::sleep(this->_waittime);
	
	this->finished();
}
