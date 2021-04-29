#include "logfunction.h"

LogFunction::LogFunction(const char* name, Log* parent){
    this->_name = name;
    this->_parent = parent;
    parent->push(this);
}


LogFunction::~LogFunction(){
    _parent->pop();
}
