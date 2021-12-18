#include "log.h"
#include "pymodule.h"

#include <Python.h>

static std::string fStr = "Executing python: ";

std::string PyModule::exec(std::string funName, PyArgs* args){
	FUN();

	{//Pre-checks
		LOGD(fStr + "Checking prerequisites...");

		if (!this->_pyInst->isRunning()){
			LOGE(fStr + "Python instance is not running");
			return "ES1";
		}

		if (!this->_is_imported){
			LOGE(fStr + "The module was not imported");
			return "ES2";
		}
	}

	std::string ret;
	PyObject* pArgs = (PyObject*)args->getArgv();
	PyObject* pFunc;
	PyObject* pRet;
	
	{//Get and check python function object
		LOGD(fStr + "Getting python function object...");

		pFunc = PyObject_GetAttrString((PyObject*)this->_pModule, funName.c_str());

		if (pFunc == NULL){
			LOGE(fStr + "Failed to load python function \"" + funName + "\": Return was NULL");
			Py_XDECREF(pFunc);
			return "ES3";
		}

		if (!PyCallable_Check(pFunc)){
			LOGE(fStr + "Failed to load python function \"" + funName + "\": Did not pass callable check");
			Py_XDECREF(pFunc);
			return "ES4";
		}
	}
	
	{//Do the function call
		LOGD(fStr + "Calling function \"" + funName + "\" of module \"" + this->_name + "\"...");
		try{
			pRet = PyObject_CallObject(pFunc, pArgs);
		} catch (...) {
			LOGE(fStr + "Terrible unknown failure when calling function \"" + funName + "\" of module \"" + this->_name + "\"");
			Py_XDECREF(pFunc);
			Py_XDECREF(pRet);
			return "ES5";
		}

		//Check the return value
		if (pRet == NULL){
			LOGE(fStr + "Failure when calling function \"" + funName + "\" of module \"" + this->_name + "\": Return was NULL");
			Py_XDECREF(pFunc);
			Py_XDECREF(pRet);
			return "ES6";
		}
	}

	{//Process return values
		LOGD(fStr + "Processing return values...");

		//Check for no (void) return type
		if (strcmp(pRet->ob_type->tp_name, "NoneType") == 0){
			ret = "V";
		} else {
			ret = _PyUnicode_AsString(pRet);
		}

		LOGD(fStr + "Function call of \"" + funName + "\" of module \"" + this->_name + "\" returned \"" + ret  + "\"");
	}

	Py_XDECREF(pFunc);
	Py_XDECREF(pRet);

	return ret;
}