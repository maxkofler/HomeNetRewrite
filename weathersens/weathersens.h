#ifndef WEATHERSENS_H
#define WEATHERSENS_H

class Weathersens;

#include "log/log.h"
#include "wsconfig/wsconfig.h"
#include "wsdriverlist/wsdriverlist.h"
#include "homenet/homenet.h"

#include <string>

class Weathersens
{
public:
    Weathersens(std::string wsConfigPath, HomeNet* hn);
    ~Weathersens();

    /**
     * @brief Loads the drivers into the python-environment
     */
    void                    loadDrivers();


    /**
     * @brief
     */
    void                    callValues();

private:
    int                     _runlevel;
                            /*  -1          Unable to start in this state
                             *  1           Configurations loaded
                             *  2           Driverlist read and parsed
                             *  3           Drivers loaded into python-environment
                             */
    HomeNet*                _hn;
    WSConfig*               _config;

    WSDriverList*           _driverlist;

    uint                    _syncTimeout;       //The time WS waits for the next sync
    std::string             _driverDir;         //The directory in that all drivers sit in
    std::string             _driverListPath;    //The path to the driverlist


    /**
     * @brief Parses the driver list submitted in the config
     * @return
     */
    bool                    parseDriverList();
};

#endif // WEATHERSENS_H
