#ifndef HOMENET_H
#define HOMENET_H

class HomeNet;

#include "log/log.h"
#include "hnconfig/hnconfig.h"
#include "hndrivers/hndrivers.h"
#include "hnpython/hnpython.h"
#include "hnhistory/hnhistory.h"

#include <string>

class HomeNet
{
public:
    HomeNet(std::string configPath);
    ~HomeNet();

    bool                sync();

    std::string         getOverview();

    friend class HNDrivers;
private:
    int                 _runlevel;

    HNConfig*           _config;

    HNPython*           _py;

    HNDrivers*          _drivers;

    HNHistory*          _history;


    //Private functions
    void                p_cleanPointers();
};

#endif // HOMENET_H
