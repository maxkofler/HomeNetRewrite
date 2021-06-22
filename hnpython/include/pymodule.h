#ifndef PYMODULE_H
#define PYMODULE_H

class PyModule;

#include <Python.h>
#include <string>

#include "log.h"

#include "hnpython.h"

class PyModule
{
public:
    PyModule();
    ~PyModule();

    friend class HNPython;
private:
    bool                                    _is_loaded;
    std::string                             _name;
    PyObject*                               _pName;         //The name in pystring form
    PyObject*                               _pModule;       //The module itself
    PyObject*                               _pDict;         //Its dictionary for symbols
};

#endif // PYMODULE_H
