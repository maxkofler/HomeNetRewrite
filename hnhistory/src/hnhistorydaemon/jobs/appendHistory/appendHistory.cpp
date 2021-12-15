#include "hnhistorydaemon/jobs/appendHistory.h"
#include "hndriver.h"
#include "log.h"

Jobs::AppendHistory::AppendHistory(HNHistoryDaemon* d, hnvalue_t value) : Job(d, JOB_APPEND_HISTORY){
	FUN();

	this->_value = value;
	this->_directory = this->_historyDaemon->getHistoryDir() + "/" +
					   ((HNDriver*)(this->_value.driver))->name() + "/";
	this->_path = this->_directory + this->_value.name + ".hnhist";
}
