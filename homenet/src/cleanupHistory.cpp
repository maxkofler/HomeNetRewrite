#include "homenet.h"
#include "log.h"

void HomeNet::cleanupHistory(){
	FUN();

	if (this->_syncs_for_cleanup == 0){
		LOGD("Not cleaning up history (deactivated)");
		return;
	}

	for (hnvalue_t* value : this->_drivers->_values){
		this->_historyDaemon->d_cleanHistory(value);
	}
}
