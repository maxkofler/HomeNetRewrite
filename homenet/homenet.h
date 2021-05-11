#ifndef HOMENET_H
#define HOMENET_H

class HomeNet;

#include "log/log.h"
#include "hnconfig/hnconfig.h"
#include "hndrivers/hndrivers.h"
#include "hnpython/hnpython.h"

#include <string>

class HomeNet
{
public:
    HomeNet(std::string configPath);
    ~HomeNet();

    friend class HNDrivers;
private:
    HNConfig*           _config;

    HNPython*           _py;

    HNDrivers*          _drivers;
};

#endif // HOMENET_H
