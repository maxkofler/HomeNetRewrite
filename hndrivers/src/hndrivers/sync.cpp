#include "hndrivers.h"

#include <ctime>

bool HNDrivers::sync(){
	FUN();

	//PyObject* args = PyTuple_New(3);
	PyArgs args(3);
	PyArgs emptyArgs(0);

	for (HNDriver* curDriver : this->_drivers){
		PyModule* curModule = this->_pyInst->getModule(curDriver->name() + ".main");

		if (curModule == nullptr){
			LOGE("Failed to load module " + curDriver->name() + "!");
			continue;
		}

		{   //Resume the driver
			if (curModule->exec("resume", &emptyArgs) == "E"){
				LOGE("Error resuming driver \"" + curDriver->name() + "\"!");
				continue;
			}
		}

		for (hnvalue_t* curValue : curDriver->getValues()){

			std::string wp = this->_workdir + "/" + curDriver->name() + "/" + curValue->name + "/";

			LOGI(   "Syncing \"" + curDriver->name() + "--" + curValue->name + "\" (gID: " +
					std::to_string(curValue->gID) + " lID: " + std::to_string(curValue->lID) + " wd: " + wp + ")");

			bool res = true;
			res &= args.setLongItem(0, curValue->gID);
			res &= args.setLongItem(1, curValue->lID);
			res &= args.setStringItem(2, wp);

			//TODO: check behavior
			if (!res){
				LOGE("Failed to set arguments");
				continue;
			}

			//std::string ret = this->_pyInst->execModFunction(curDriver->name() + ".main", "getValue", args.getArgv());

			std::string ret = curModule->exec("getValue", &args);

			curValue->datatype = ret[0];
			curValue->value = ret.substr(1, ret.length()-1);
			curValue->syncTime = std::time(0);


			this->_historyDaemon->d_appendHistory(*curValue);
		}

		{   //Pause the driver
			if (curModule->exec("pause", &emptyArgs) == "E"){
				LOGE("Error stopping driver \"" + curDriver->name() + "\"!");
			}
		}
	}

	return true;
}
