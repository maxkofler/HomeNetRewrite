#include "logfunction.h"

#include <iostream>

LogFunction::LogFunction(const char* name, Log* parent){
    this->_name = name;
    this->_parent = parent;
    parent->push(this);
    hlog->log("Entering function \"" + std::string(name) + "\"", 10);
}


LogFunction::~LogFunction(){
    hlog->log("Leaving function \"" + std::string(this->_name) + "\"", 10);
    _parent->pop();
}
