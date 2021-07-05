#include "hnpython.h"

#include <Python.h>

bool HNPython::loadModule(std::string name){
    FUN();

    if (!this->_py_running){
        LOGE("Python-interpreter is not running, can not load a module!");
        return false;
    }

    PyModule* mod = new PyModule();
    //Tell the module its name
    mod->_name = name;
    mod->_pName = (void*) PyUnicode_FromString(name.c_str());

    //Import the module
    mod->_pModule = (void*) PyImport_Import((PyObject*) mod->_pName);

    //Check if the import was done
    if (mod->_pModule == NULL){
        LOGE("Could not import module \"" + mod->_name + "\"!");
        return false;
    }

    //Load the dictionary
    mod->_pDict = PyModule_GetDict((PyObject*) mod->_pModule);

    //The module is loaded!
    mod->_is_loaded = true;
    LOGD("Loaded module \"" + mod->_name + "\"!");
    this->_modules[mod->_name] = mod;
    return true;
}
