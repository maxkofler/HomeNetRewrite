#ifndef WEATHERSENS_H
#define WEATHERSENS_H

class Weathersens;

#include "log/log.h"
#include "wsconfig/wsconfig.h"
#include "wsdriverlist/wsdriverlist.h"
#include "homenet/homenet.h"

#include <string>
#include <mutex>
#include <thread>

class Weathersens
{
public:
    Weathersens(std::string wsConfigPath, HomeNet* hn);
    ~Weathersens();

    /**
     * @brief   Loads the drivers into the python-environment
     */
    void                    loadDrivers();


    /**
     * @brief   Calls all values from all drivers
     */
    void                    callValues();

    /**
     * @brief   This starts the syncing loop in a seperate thread
     *          and syncs all the values regularly
     * @return
     */
    bool                    startSyncLoop();

    /**
     * @brief   Stops the syncing loop and waits for its cleanup
     */
    void                    stopSyncLoop();

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

    bool                    _runSyncLoop;       //Whether the loop should run or not

    std::thread*            _t_syncloop;        //The thread that contains the sync loop

    std::mutex              _m_driverlist;      //A mutex that protects the driverlist
    std::mutex              _m_runSyncLoop;     //The mutex to the runSyncLoop variable

    /**
     * @brief Parses the driver list submitted in the config
     * @return
     */
    bool                    parseDriverList();

    /**
     * @brief The loop in that the syncing is happening regularly
     */
    void                    syncLoop();
};

#endif // WEATHERSENS_H
