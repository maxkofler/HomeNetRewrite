#include "hnpython.h"

HNPython::HNPython(){
    Py_Initialize();
}

HNPython::~HNPython(){
    Py_Finalize();
}

void HNPython::restartPython(){
    Py_Finalize();
    Py_Initialize();
}

void HNPython::addPythonPath(std::string path){
    QString pPath;
    pPath.fromStdString(path);
    PySys_SetPath(pPath.toStdWString().c_str());
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
