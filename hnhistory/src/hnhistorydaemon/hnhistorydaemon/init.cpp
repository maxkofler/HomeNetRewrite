#include "hnhistorydaemon.h"
#include "log.h"

bool HNHistoryDaemon::init(HNConfig &config){
	FUN();

	std::string fStr = "Starting history daemon: ";

	std::string maxThreads = config.getFirstConfig("historyThreads");
	if (maxThreads == ""){
		LOGD(fStr + "Defaulting to 2 history threads");
		this->_maxThreads = 2;
	}else{
		try{
			this->_maxThreads = stoi(maxThreads);
			LOGD(fStr + "Using " + std::to_string(this->_maxThreads) + " history threads");
		} catch (...){
			LOGE(fStr + "Failed to init history daemon: invalid <historyThreads> config");
			return false;
		}
	}

	this->_historyDir = config.getFirstConfig("historydir", true);

	LOGI(this->_cN + "Using " + std::to_string(this->_maxThreads) + " threads");

	return true;
}
