#include "hndrivers.h"

HNDrivers::HNDrivers(){
	FUN();

	this->_rl_initialized = false;
	this->_rl_driversloaded = false;
	this->_nextVId = 0;
}

HNDrivers::~HNDrivers(){
	FUN();

	{//Remove all values
		LOGI("Destroying HNDrivers: Clearing values");
		for (int i = 0; i < this->_values.size(); i++)
			delete this->_values.at(i);
		this->_values.clear();
	}

	{//Remove all drivers
		LOGI("Destroying HNDrivers: Clearing drivers");
		for (int i = 0; i < this->_drivers.size(); i++)
			delete this->_drivers.at(i);
		this->_drivers.clear();
	}
}
