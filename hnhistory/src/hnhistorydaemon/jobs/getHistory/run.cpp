#include "hnhistorydaemon/jobs/getHistory.h"
#include "log.h"

void Jobs::GetHistory::run(){
	FUN();
	this->_is_running = true;

	LOGD("Starting to get history...");

	QThread::sleep(10);

	LOGD("Finished getting history");

	this->finished();
}
