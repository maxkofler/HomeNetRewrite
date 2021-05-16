#ifndef HOMENET_H
#define HOMENET_H

class HomeNet;

#include "log/log.h"
#include "hnconfig/hnconfig.h"
#include "hndrivers/hndrivers.h"
#include "hnpython/hnpython.h"
#include "hnhistory/hnhistory.h"

#include <string>
#include <mutex>
#include <thread>

class HomeNet
{
public:
    HomeNet(std::string configPath);
    ~HomeNet();

    bool                sync();

    bool                startSyncLoop();
    bool                stopSyncLoop();

    bool                isSyncLoopRunning();

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

    //Syncloop
    int                 _syncloop_sleeptime;
    std::mutex          _m_syncing;
    bool                _runSyncLoop;
    std::mutex          _m_runSyncLoop;
    std::thread*        _t_syncLoop;
    void                p_syncLoop();
};

#endif // HOMENET_H
