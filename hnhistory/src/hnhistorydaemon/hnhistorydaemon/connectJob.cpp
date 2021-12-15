#include "hnhistorydaemon.h"
#include "log.h"

void HNHistoryDaemon::connectJob(Job* job){
	FUN();

	LOGD("History daemon: Connecting new jobs signals to deamon slots");

	qRegisterMetaType<size_t>("size_t");
	this->connect(job, &Job::jobFinished, this, &HNHistoryDaemon::jobJoined,
				  Qt::ConnectionType::DirectConnection);
}
