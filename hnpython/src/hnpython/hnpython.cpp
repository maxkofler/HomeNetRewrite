#include "hnpython.h"

HNPython::HNPython(){
    FUN();
    this->_py_running = false;
}

HNPython::~HNPython(){
    FUN();

    //Delete all modules
	//@TODO investigate map clear
    int modcount = 0;
    std::map<std::string, PyModule*>::iterator it = this->_modules.begin();
    while (it != this->_modules.end()){
        delete it->second;
        it++;
        modcount++;
    }
    LOGD("Cleaned " + std::to_string(modcount) + " modules from memory!");

	if (this->_py_running){
        LOGW("Python-interpreter is still running, forcing quit");
        this->stopPython();
    }
}
