#ifndef HOMENET_H
#define HOMENET_H

class HomeNet;

#include "log/log.h"
#include "hnconfig/hnconfig.h"
#include "weathersens/weathersens.h"
#include "hnpython/hnpython.h"

#include <string>

class HomeNet
{
public:
    HomeNet(std::string configPath);
    ~HomeNet();

    /**
     * @brief Starts the Weathersens sub-module
     * @return          Whether the start was successfull
     */
    bool                startWS();

    /**
     * @brief Ends the Weathersens sub-module
     * @return
     */
    void                endWS();

    friend class Weathersens;
private:
    HNConfig*           _config;

    HNPython*           _py;

    Weathersens*        _ws;
};

#endif // HOMENET_H
