#include "hnhistorydaemon/jobs/cleanHistory.h"
#include "hndriver.h"
#include "log.h"

Jobs::CleanHistory::CleanHistory(HNHistoryDaemon* d, hnvalue_t* value) : Job(d, JOB_CLEAN_HISTORY){
	FUN();

	this->_value = value;
	this->_path = this->_historyDaemon->getHistoryDir() + "/" +
				  ((HNDriver*)(this->_value->driver))->name() + "/" +
				  this->_value->name + ".hnhist";
}
