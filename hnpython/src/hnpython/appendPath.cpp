#include "hnpython.h"

#include <Python.h>

bool HNPython::appendPath(std::string path){
    FUN();

    if (!this->_py_running){
        LOGE("Python-interpreter is not running, can not append path!");
        return false;
    }

    std::string pCommand = "sys.path.append(\"" + path + "\")";
    PyRun_SimpleString(pCommand.c_str());
    LOGD("Appended python-path: \"" + path + "\"");
    return true;
}
