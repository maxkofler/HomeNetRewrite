#include "hnhistorydaemon.h"

bool HNHistoryDaemon::stop(){
	FUN();

	std::string fStr = "Stopping history daemon: ";
	LOGI(fStr + "Stopping...");

	{//Let the event loop finish
		LOGI(fStr + "Releasing event loop for finishing");
		this->_run = false;
		this->release();
		
		LOGI(fStr + "Waiting for event loop to finish...");
		this->wait(QDeadlineTimer::Forever);
		LOGI(fStr + "Event loop finished");
	}


}
