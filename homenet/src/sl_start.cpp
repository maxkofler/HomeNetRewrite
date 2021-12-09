#include "homenet.h"

#include "homenet_status.h"

#include "configQueryException.h"

void HomeNet::start(){
	FUN();

	try{
		std::string fStr = "Starting HomeNet: ";

		{
			LOGI(fStr + "Parsing config");
			if (!this->_config->parse("/etc/homenet/hnconfig.conf")){
				LOGE(fStr + "Error in parsing config!");
				p_stopOnError();
				return;
			}

			LOGI(fStr + "Getting configs");

			this->_time_sync = stoi(this->_config->getFirstConfig("synctime", true));

			{//Set the cleanup syncs
				std::string cleanupStr = this->_config->getFirstConfig("cleanupSyncs");
				if (cleanupStr.empty())
					this->_syncs_for_cleanup = 0;
				else
					this->_syncs_for_cleanup = stoi(cleanupStr);
			}
		}

		{
			LOGI(fStr + "Starting Python");
			this->_python->startPython(true);
		}

		{
			LOGI(fStr + "Initializing history module");

			if (!this->_history->init(*this->_config)){
				LOGE(fStr + "Error in initializing history module!");
				p_stopOnError();
				return;
			}
		}

		{
			LOGI(fStr + "Initializing drivers");

			if (!this->_drivers->init(*this->_config, this->_python, this->_history, this->_historyDaemon)){
				LOGE(fStr + "Error in initializing drivers!");
				p_stopOnError();
				return;
			}

			LOGI(fStr + "Loading drivers");
			if (!this->_drivers->loadDrivers()){
				LOGE(fStr + "Error in loading drivers!");
				p_stopOnError();
				return;
			}
		}

		{
			LOGI(fStr + "Starting networking module");

			if (!this->_networking->start(*this->_config)){
				LOGE(fStr + "Error in starting networking module!");
				p_stopOnError();
				return;
			}
		}

		{
			LOGI(fStr + "Starting history daemon");
			if (!this->_historyDaemon->init(*this->_config)){
				LOGE(fStr + "Error in starting history daemon!");
				p_stopOnError();
				return;
			}
			this->_historyDaemon->start();

			this->cleanupHistory();
		}

		{
			LOGI(fStr + "Starting syncloop with " + std::to_string(this->_time_sync) + " seconds");

			this->_timerSync = new QTimer(this);
			connect(this->_timerSync, &QTimer::timeout, this, QOverload<>::of(&HomeNet::sync));
			this->_timerSync->start(this->_time_sync*1000);
		}
	}

	catch(ConfigQueryException e){
		LOGE("Could not find a critical configuration: " + e.key);
		p_stopOnError();
		return;
	}

	catch(...){
		LOGE("A critical error raised during execution!");
		p_stopOnError();
		return;
	}
}

void HomeNet::p_stopOnError(){
	stateHomeNet.running = false;
	emit HomeNet::stop();
}
