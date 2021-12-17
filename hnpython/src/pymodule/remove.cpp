#include "log.h"
#include "pymodule.h"

#include <Python.h>

void PyModule::remove(){
	FUN();

	LOGD("Removing Python module \"" + this->_name + "\"");

	if (this->_is_imported){
		Py_XDECREF(this->_pName);
		Py_XDECREF(this->_pModule);
		this->_is_imported = false;
	}
}
