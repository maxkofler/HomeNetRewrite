#include "hnhistorydaemon/jobs/stop.h"
#include "log.h"

Jobs::Stop::Stop(HNHistoryDaemon* d) : Job(d, JOB_VOID){
	FUN();
}
