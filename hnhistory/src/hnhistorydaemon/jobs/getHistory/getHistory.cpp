#include "hnhistorydaemon/jobs/getHistory.h"
#include "log.h"

Jobs::GetHistory::GetHistory(HNHistoryDaemon* d, hnvalue_t value) : Job(d, JOB_GET_HISTORY){
	FUN();
}
