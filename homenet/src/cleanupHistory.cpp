#include "homenet.h"
#include "log.h"

void HomeNet::cleanupHistory(){
	FUN();

	for (hnvalue_t* value : this->_drivers->_values){
		this->_historyDaemon->d_cleanHistory(value);
	}
}
