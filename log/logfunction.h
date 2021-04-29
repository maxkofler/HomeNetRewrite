#ifndef LOGFUNCTION_H
#define LOGFUNCTION_H

class LogFunction;

#include "log.h"

class LogFunction{
public:
    LogFunction(const char* name, Log* log);
    ~LogFunction();

    const char*     name(){return this->_name;}
private:
    const char*     _name;
    Log*            _parent;
};

#endif // LOGFUNCTION_H
