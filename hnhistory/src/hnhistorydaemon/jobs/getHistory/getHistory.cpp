#include "hnhistorydaemon/jobs/getHistory.h"
#include "log.h"

GetHistory::GetHistory(job_type type) : Job(JOB_GET_HISTORY, type){
	FUN();

}
