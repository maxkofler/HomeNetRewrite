#include "pyargs.h"
#include <Python.h>

#include "log.h"

PyArgs::PyArgs(int argc){
    FUN();
    this->_argc = argc;
    this->_argv = (void*)PyTuple_New(this->_argc);
}

PyArgs::~PyArgs(){
	FUN();

	Py_XDECREF(this->_argv);
}