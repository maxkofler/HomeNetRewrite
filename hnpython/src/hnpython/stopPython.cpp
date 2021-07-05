#include "hnpython.h"

#include <Python.h>

void HNPython::stopPython(){
    FUN();
    if (this->_py_running){
        Py_Finalize();
        LOGI("Stopped python-interpreter");
    }
    else
        LOGE("Python-interpreter is not running!");
}
