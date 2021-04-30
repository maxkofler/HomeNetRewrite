#include "pymodule.h"

PyModule::PyModule(){
    FUN();
    this->_is_loaded = false;
}

std::string PyModule::execFunction(std::string name, PyObject* args){
    FUN();
    std::string ret;

    //Check if the module is loaded correctly
    if (this->_pModule == NULL && this->_is_loaded){
        LOGE("Could not execute function \"" + name + "\" module not loaded!");
        return ret;
    }

    //Create ob object for the function and load it with its name
    PyObject* pFunc;
    pFunc = PyDict_GetItemString(this->_pDict, name.c_str());

    //Check if the function is callable
    if (!PyCallable_Check(pFunc)){
        LOGE("Could not find the function \"" + name + "\" in this module!");
        return ret;
    }

    //Call the object
    PyObject* res = PyObject_CallObject(pFunc, args);

    LOGD("Called python function \"" + name + "\" with result \"" + _PyUnicode_AsString(res) + "\"");

    //Return
    return _PyUnicode_AsString(res);
}
