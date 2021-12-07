#include "hnhistorydaemon/jobs/getHistory.h"
#include "log.h"

Jobs::GetHistory::GetHistory(Args args) : Job(JOB_GET_HISTORY, args){
	FUN();
}