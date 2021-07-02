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

    /**
     * @brief   Initializes this module with its needed objects, parses driverlist if existing
     * @param   config                      A reference to the main HNConfig
     * @param   pyInstance                  A pointer to the core HNPython instance
     */
    bool                                    init(HNConfig& config, HNPython* pyInstance);

    /**
     * @brief   Loads the drivers parsed from the driverlist provided from the HNConfig to init()
     */
    bool                                    loadDrivers();

private:
    HNParser                                _driverlistParser;
    HNPython*                               _pyInst;

    std::string                             _driverlistPath;
    std::string                             _driversPath;
    std::string                             _workdir;

    bool                                    _rl_initialized;
    bool                                    _rl_driversloaded;




    bool                                    p_parseDriverlist();
};

#endif
