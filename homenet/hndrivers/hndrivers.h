#ifndef HNDRIVERS_H
#define HNDRIVERS_H

class HNDrivers;

#include "log/log.h"
#include "hndriver/hndriver.h"
#include "homenet/hnconfig/hnconfig.h"
#include "parser/parser.h"

#include <vector>
#include <string>

class HNDrivers
{
public:
    HNDrivers();
    ~HNDrivers();

    /**
     * @brief Fetches driverlist, imports and starts all drivers
     * @param config            The HNConfig for the driverlist entry
     * @return
     */
    bool                        start(HNConfig* config);

private:
    Parser*                     _driverListParser;
    int                         _runlevel;

    std::vector<HNDriver>       _drivers;

    //configs
    std::string                 _driverListPath;
    std::string                 _driversPath;
    int                         _syncTime;

    //ids
    uint                        _nextId;

    //Functions
    void                        p_fetchDrivers();
};

#endif // HNDRIVERS_H
