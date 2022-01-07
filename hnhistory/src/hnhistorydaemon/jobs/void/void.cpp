#include "hnhistorydaemon/jobs/void.h"
#include "log.h"

Jobs::Void::Void(HNHistoryDaemon* d, int time) : Job(d, JOB_VOID){
	FUN();

	this->_waittime = time;
}
