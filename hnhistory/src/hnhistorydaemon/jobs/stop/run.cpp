#include "hnhistorydaemon/jobs/stop.h"
#include "log.h"



void Jobs::Stop::run(){
	FUN();

	this->_is_running = true;

	QObject::connect(this, &Jobs::Stop::stop, this->_historyDaemon, &HNHistoryDaemon::stop, Qt::ConnectionType::QueuedConnection);

	LOGD("Stop job: Stopping history daemon");
	emit stop();
	
	this->finished();
}
