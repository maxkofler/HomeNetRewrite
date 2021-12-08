#include "hnhistorydaemon.h"
#include "log.h"

void HNHistoryDaemon::jobJoined(size_t id){
	FUN();

	LOGI("History daemon: A job joined!");

	this->release();
}
