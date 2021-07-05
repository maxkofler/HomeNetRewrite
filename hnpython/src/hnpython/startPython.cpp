#include "hnpython.h"

#include <Python.h>

void HNPython::startPython(bool force){
    FUN();
    if (this->_py_running){
        if (force)
            Py_Finalize();
        else{
            LOGE("Python-interpreter is already running!");
            return;
        }
    }

    Py_Initialize();
    PyRun_SimpleString("import sys");
    this->_py_running = true;
    LOGI("Started python-interpreter");
}
