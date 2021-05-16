#ifndef HNDRIVERS_H
#define HNDRIVERS_H

class HNDrivers;

#include "log/log.h"
#include "hndriver/hndriver.h"
#include "homenet/hnconfig/hnconfig.h"
#include "homenet/hnpython/hnpython.h"
#include "homenet/hnhistory/hnhistory.h"
#include "parser/parser.h"

#include <vector>
#include <string>

class HNDrivers{
public:
    HNDrivers();
    ~HNDrivers();

    /**
     * @brief Fetches driverlist, imports and starts all drivers
     * @param config            The HNConfig for the driverlist entry
     * @return
     */
    bool                        start(HNConfig* config, HNPython* pyInst);

    /**
     * @brief Syncs all driver values with the python modules
     * @param history           A reference to the history module
     * @return
     */
    bool                        sync(HNHistory& history);

    /**
     * @brief Returns a string containing a driver overview
     * @return
     */
    std::string                 getOverview();

private:
    Parser*                     _driverListParser;
    HNPython*                   _python;
    int                         _runlevel;

    std::vector<HNDriver>       _drivers;

    //configs
    std::string                 _driverListPath;
    std::string                 _driversPath;
    std::string                 _workDir;
    int                         _syncTime;

    //ids
    uint                        _nextId;

    //Functions
    void                        p_fetchDrivers();
    bool                        p_importDrivers();
};

#endif // HNDRIVERS_H
