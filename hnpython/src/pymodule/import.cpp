#include "log.h"
#include "pymodule.h"
#include <Python.h>

static std::string fStr = "Import PyModule: ";

bool PyModule::import(std::string name){
	FUN();
	this->_name = name;

	LOGI("Importing python module \"" + this->_name + "\"...");

	{//Check if python interpreter is running
		LOGD(fStr + "Checking for running interpreter...");
		if (!this->_pyInst->isRunning()){
			LOGE(fStr + "Python interpreter is not running");
			return false;
		}
	}

	{//Create the name
		LOGD(fStr + "Creating python name of module...");
		this->_pName = PyUnicode_DecodeFSDefault(name.c_str());
		if (this->_pName == NULL){
			LOGE(fStr + "Failed to create module name");
			PyErr_Print();
			Py_XDECREF(this->_pName);
			return false;
		}
	}

	{//Then try to import the module
		LOGD(fStr + "Importing module...");
		this->_pModule = PyImport_Import((PyObject*)this->_pName);
		if (this->_pModule == NULL){
			LOGE(fStr + "Failed to import module");
			Py_XDECREF(this->_pName);
			Py_XDECREF(this->_pModule);
			return false;
		}
	}

	this->_is_imported = true;
	return true;
}
