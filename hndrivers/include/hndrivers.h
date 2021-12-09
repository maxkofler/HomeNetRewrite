#ifndef __HNDRIVERS_H__
#define __HNDRIVERS_H__

class HNDrivers;

#include <string>
#include <vector>

#include "log.h"

#include "hndriver.h"
#include "hnconfig.h"
#include "hnparser.h"
#include "hnpython.h"
#include "hnhistory.h"
#include "hnhistorydaemon.h"

class HNDrivers{
public:
    HNDrivers();
    ~HNDrivers();

    /**
     * @brief   Initializes this module with its needed objects, parses driverlist if existing
     * @param   config                      A reference to the main HNConfig
     * @param   pyInstance                  A pointer to the core HNPython instance
     */
    bool                                    init(HNConfig& config, HNPython* pyInstance, HNHistory* history, HNHistoryDaemon* daemon);

    /**
     * @brief   Loads the drivers parsed from the driverlist provided from the HNConfig to init()
     */
    bool                                    loadDrivers();

    /**
     * @brief   Calls all values from the drivers
     */
    bool                                    sync();

    /**
     * @brief   Returns a vector of pointers to all the values
     */
    std::vector<hnvalue_t*>*                getValues(){return &this->_values;}

    /**
     * @brief   Returns if this module can be used
     */
    bool                                    ok(){return this->_rl_driversloaded && this->_rl_initialized;}

	friend class HomeNet;
private:
    HNParser                                _driverlistParser;
    HNPython*                               _pyInst;
    HNHistory*                              _history;
	HNHistoryDaemon*						_historyDaemon;

    std::vector<HNDriver*>                  _drivers;
    std::vector<hnvalue_t*>                 _values;

    std::string                             _driverlistPath;
    std::string                             _driversPath;
    std::string                             _workdir;

    bool                                    _rl_initialized;
    bool                                    _rl_driversloaded;

    bool                                    p_parseDriverlist();
    bool                                    p_importDrivers();
    bool                                    p_startDrivers();
    size_t                                  _nextVId;
};

#endif
