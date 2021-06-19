#ifndef HOMENET_H
#define HOMENET_H

class HomeNet;

#include "log/log.h"
#include "hnconfig/hnconfig.h"
#include "hndrivers/hndrivers.h"
#include "hnpython/hnpython.h"
#include "hnhistory/hnhistory.h"
#include "hnnetworking/hnnetworking.h"

#include <string>
#include <mutex>
#include <thread>
#include <QObject>

class HomeNet : public QObject{
    Q_OBJECT
public:
    /**
     * @brief HomeNet
     * @param configPath        The path to the config file used in HomeNet
     */
    HomeNet(std::string configPath);
    ~HomeNet();
    /**
     * @brief   Calls in the values from the drivers
     * @return
     */
    bool                        sync();

    /**
     * @brief   Starts the loop in that HomeNet constantly syncs the values in a new thread
     * @return
     */
    bool                        startSyncLoop();

    /**
     * @brief   Stops the loop in that HomeNet syncs the values, blocks for some time
     * @return
     */
    bool                        stopSyncLoop();

    /**
     * @brief   Returns whether the sync loop is currently running or not
     * @return
     */
    bool                        isSyncLoopRunning();

    /**
     * @brief   Returns a string containing an overview of the current state of HomeNet
     * @return
     */
    std::string                 getOverview();

signals:
    void                        synced();

private:
    /**
     * @brief _runlevel         The runlevel HomeNet is currently in
     */
    int                         _runlevel;

    /**
     * @brief _config           Represents the config file used to fetch settings for HomeNet
     */
    HNConfig*                   _config;

    /**
     * @brief _py               The wrapper for the Python - api
     */
    HNPython*                   _py;

    /**
     * @brief _drivers          Contains all the drivers and their values
     */
    HNDrivers*                  _drivers;

    /**
     * @brief _history          Util for handling history entries
     */
    HNHistory*                  _history;

    /**
     * @brief _networking       Submodule to handle incoming networking connections
     *                          and value queries
     */
    HNNetworking*               _networking;


    //Private functions
    void                        p_cleanPointers();

    //Syncloop
    //The time that passes between syncs
    int                         _syncloop_sleeptime;
    //A mutex locking during syncing
    std::mutex                  _m_syncing;
    //Whether the syncloop should keep running
    bool                        _runSyncLoop;
    //A mutex to protect _runSyncLoop
    std::mutex                  _m_runSyncLoop;
    //The thread in that the syncloop is running in
    std::thread*                _t_syncLoop;

    //The function that runs the sync loop
    void                        p_syncLoop();
};

#endif // HOMENET_H
