#include "pyargs.h"
#include "log.h"

#include <Python.h>

bool PyArgs::setLongItem(int pos, long value){
	FUN();

	PyObject* arg;

	LOGD("Setting arg " + std::to_string(pos) + " to long " + std::to_string(value));

	{//Check if the index is out of bounds
		if (pos >= this->_argc || pos < 0){
			LOGE(	"Argument index out of bounds: " + std::to_string(pos) + " / (0 -> " +
					std::to_string(this->_argc) + ")");
			return false;
		}
	}


	{//Create and check argument
		arg = PyLong_FromLong(value);

		if (!arg){
			LOGE("Failed to create python long from " + std::to_string(value));
			Py_XDECREF(arg);
			return false;
		}
	}

	PyTuple_SetItem((PyObject*)this->_argv, pos, arg);

	//TODO check memory of arg

	return true;
}
