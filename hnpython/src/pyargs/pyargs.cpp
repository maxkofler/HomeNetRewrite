#include "pyargs.h"
#include <Python.h>

#include "log.h"

PyArgs::PyArgs(size_t argc){
    FUN();
    this->_argc = argc;
    this->_argv = (void*)PyTuple_New(this->_argc);
}