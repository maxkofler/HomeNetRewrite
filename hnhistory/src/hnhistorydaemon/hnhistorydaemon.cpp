#include "hnhistorydaemon.h"
#include "log.h"

HNHistoryDaemon::HNHistoryDaemon(){
	FUN();

}

HNHistoryDaemon::~HNHistoryDaemon(){
	FUN();

	this->stop();
}