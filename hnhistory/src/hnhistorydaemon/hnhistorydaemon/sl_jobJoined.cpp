#include "hnhistorydaemon.h"
#include "log.h"

void HNHistoryDaemon::jobJoined(size_t id){
	FUN();

	LOGD("History daemon: Job " + std::to_string(id) + " joined");

	this->_m_eventLoop.unlock();
}
