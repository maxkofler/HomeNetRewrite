#include "hnpython.h"
#include <Python.h>

static std::string fStr = "Loading module: ";

bool HNPython::loadModule(std::string name){
    FUN();

	{//Check if the module is not already lodaed
		if (this->_modules.count(name) > 0){
			LOGW(fStr + "Module \"" + name + "\" seems to be already imported!");

			//Check if the module is not a nullptr
			if (this->_modules[name] == nullptr){
				LOGD(fStr + "Module \"" + name + "\" is no more in memory, overriding it...");
				this->_modules.erase(name);
			} else {
				if (this->_modules[name]->_is_imported)
				LOGE(fStr + "Failed to load module \"" + name + "\": It is already loaded");
				return false;
			}
		}
	}

	PyModule* newMod = new PyModule(this);
	
	//Import the module
	bool ret = newMod->import(name);

	//If the import failed
	if (!ret){
		delete newMod;
		LOGD(fStr + "Removing module \"" + name + "\" from modules due to failed import");
		
		if (this->_modules.count(name) > 0)
			this->_modules.erase(name);

		return false;
	}

	LOGD(fStr + "Adding module \"" + name + "\" to modules list...");
	this->_modules[name] = newMod;

	return true;
}
