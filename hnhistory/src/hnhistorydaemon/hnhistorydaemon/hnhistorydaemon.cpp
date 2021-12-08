#include "hnhistorydaemon.h"
#include "log.h"

HNHistoryDaemon::HNHistoryDaemon(){
	FUN();

}

HNHistoryDaemon::~HNHistoryDaemon(){
	FUN();

	//TODO: wait for all jobs to finish or destroy them [memory leak]

	this->stop();
}