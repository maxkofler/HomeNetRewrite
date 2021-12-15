#include "hndrivers.h"

#include <ctime>

bool HNDrivers::sync(){
	FUN();

	//PyObject* args = PyTuple_New(3);
	PyArgs args(3);

	for (HNDriver* curDriver : this->_drivers){

		{   //Resume the driver
			if (this->_pyInst->execModFunction(curDriver->name() + ".main", "resume", nullptr) == "E"){
				LOGE("Error resuming driver \"" + curDriver->name() + "\"!");
				continue;
			}
		}

		for (hnvalue_t* curValue : curDriver->getValues()){

			std::string wp = this->_workdir + "/" + curDriver->name() + "/" + curValue->name + "/";

			LOGI(   "Syncing \"" + curDriver->name() + "--" + curValue->name + "\" (gID: " +
					std::to_string(curValue->gID) + " lID: " + std::to_string(curValue->lID) + " wd: " + wp + ")");

			args.setItem(0, "i#", curValue->gID);
			args.setItem(1, "i#", curValue->lID);
			args.setItem(2, "s#", wp.c_str(), wp.length());

			std::string ret = this->_pyInst->execModFunction(curDriver->name() + ".main", "getValue", args.getArgv());

			curValue->datatype = ret[0];
			curValue->value = ret.substr(1, ret.length()-1);
			curValue->syncTime = std::time(0);


			this->_historyDaemon->d_appendHistory(*curValue);
		}

		{   //Pause the driver
			if (this->_pyInst->execModFunction(curDriver->name() + ".main", "pause", nullptr) == "E"){
				LOGE("Error stopping driver \"" + curDriver->name() + "\"!");
			}
		}
	}

	return true;
}
