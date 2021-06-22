#include "hnpython.h"

std::string HNPython::execModFunction(std::string modName, std::string funName, PyObject *args){
    FUN();

    if (!this->_py_running){
        LOGE("Python-interpreter is not running, can not execute a function!");
        return "ES1";
    }

    if (this->_modules.count(modName) <= 0){
        LOGE("Could not find the specified module as loaded: \"" + modName + "\"!");
        return "ES2";
    }

    PyModule* curMod = this->_modules[modName];

    PyObject* pFunc;
    pFunc = PyDict_GetItemString(curMod->_pDict, funName.c_str());

    //Check if the function is callable
    if (!PyCallable_Check(pFunc)){
        LOGE("Function \"" + funName + "\" of module \"" + modName + "\" seems not to be callable (not present?)");
        return "ES3";
    }

    PyObject* pyret;
    //Critical calling of function
    try{
        pyret = PyObject_CallObject(pFunc, args);
    }catch(...){
        LOGE("Fatal exception happened during call of function \"" + funName + "\" of module \"" + modName + "\"!");
        PyRun_SimpleString("print(\"\", flush=True)");
        return "ES4";
    }

    //This indicates an error too
    if (pyret == NULL){
        LOGE("Function \"" + funName + "\" of module \"" + modName + "\" had an error!");
        return "ES4";
    }

    //Check for no (void) return value
    int res = strcmp(pyret->ob_type->tp_name, "NoneType");
    if (res == 0){
        LOGD("Function \"" + funName + "\" of module \"" + modName + "\" has no return value!");
        return "V";
    }

    //And return
    std::string ret = _PyUnicode_AsString(pyret);
    LOGD("Function \"" + funName + "\" of module \"" + modName + "\" returned \"" + ret + "\"!");

    return ret;
}
