#ifndef __HNDRIVERS_H__
#define __HNDRIVERS_H__

class HNDrivers;

#include <string>

#include "log.h"

#include "hnconfig.h"
#include "hnparser.h"
#include "hnpython.h"

class HNDrivers{
public:
    HNDrivers();
    ~HNDrivers();

    bool                                    init(HNConfig& config, HNPython* pyInstance);

private:
    HNParser                                _driverlistParser;
    HNPython*                               _pyInst;

    std::string                             _driverlistPath;
    std::string                             _driversPath;
    std::string                             _workdir;


};

#endif
