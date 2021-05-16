#include "hnpython.h"

HNPython::HNPython(){
    FUN();
    Py_Initialize();
    PyRun_SimpleString("import sys");
    LOGI("Started python!");
}

HNPython::~HNPython(){
    FUN();
    LOGI("Stopping python...");
    Py_Finalize();
    LOGI("Stopped python!");
}

void HNPython::restartPython(){
    FUN();
    Py_Finalize();
    Py_Initialize();
    PyRun_SimpleString("import sys");
    LOGI("Restarted python!");
}

void HNPython::addPythonPath(std::string path){
    FUN();

    std::string pPath = "sys.path.append(\"" + path + "\")";
    PyRun_SimpleString(pPath.c_str());

    LOGD("Added \"" + pPath + "\" from \"" + path + "\" to python-PATH");
}

PyModule HNPython::loadModule(std::string name){
    FUN();
    PyModule mod;
    //Convert the string name to a python type
    mod._pName = PyUnicode_FromString(name.c_str());

    //Import the module
    mod._pModule = PyImport_Import(mod._pName);

    if (mod._pModule != NULL){
        mod._pDict = PyModule_GetDict(mod._pModule);
        LOGD("Imported module \"" + name + "\"!");
        mod._is_loaded = true;
    }else{
        LOGE("Could not import module \"" + name + "\"!");
    }
    return mod;
}
