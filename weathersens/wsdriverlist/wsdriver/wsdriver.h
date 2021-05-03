#ifndef WSDRIVER_H
#define WSDRIVER_H

class WSDriver;

#include <string>

#include "log/log.h"

class WSDriver
{
public:
    WSDriver();

private:
    std::string                 _name;
};

#endif // WSDRIVER_H
