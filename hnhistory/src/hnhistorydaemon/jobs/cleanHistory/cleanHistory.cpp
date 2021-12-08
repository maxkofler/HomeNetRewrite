#include "hnhistorydaemon/jobs/cleanHistory.h"
#include "log.h"

Jobs::CleanHistory::CleanHistory(HNHistoryDaemon* d, std::string path) : Job(d, JOB_CLEAN_HISTORY){
	FUN();

	this->_path = path;
}
