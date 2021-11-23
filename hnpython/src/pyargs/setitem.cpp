#include "pyargs.h"
#include <Python.h>

#include "log.h"

void PyArgs::setItem(size_t pos, const char *type, int value){
    FUN();
    PyTuple_SetItem((PyObject*)this->_argv, pos, Py_BuildValue(type, value));
    LOGD("Setting item " + std::to_string(pos) + " to " + std::to_string(value) + " of type " + type);
}

void PyArgs::setItem(size_t pos, const char *type, const char *value, int len){
    FUN();
    PyTuple_SetItem((PyObject*)this->_argv, pos, Py_BuildValue(type, value, len));
    LOGD("Setting item " + std::to_string(pos) + " to \"" + value + "\" of type " + type);
}
