#include "hnhistorydaemon.h"

void HNHistoryDaemon::release(){
	FUN();

	LOGD("Releasing history daemon...");
	this->_m_operationPending.unlock();
}
