#ifndef __HOMENET_H__
#define __HOMENET_H__

class HomeNet;

#include <signal.h>

#include <QObject>
#include <QTimer>

#include "log.h"

#include "hndrivers.h"
#include "hnconfig.h"
#include "hnpython.h"
#include "hnnetworking.h"
#include "hnhistory.h"
#include "hnhistorydaemon.h"

class HomeNet : public QObject{
    Q_OBJECT

public:
    HomeNet(QObject* parent = 0) : QObject(parent){
        FUN();

        signal(SIGINT, p_sigHandler);

        this->_config = new HNConfig();
        this->_python = new HNPython();
        this->_drivers = new HNDrivers();
        this->_history = new HNHistory();
		this->_historyDaemon = new HNHistoryDaemon();
        this->_networking = new HNNetworking(this->_drivers, this->_history, this);
    }
    ~HomeNet();

public slots:
    void                                    start();

private slots:
    void                                    sync();

signals:
    void                                    stop();

private:
    HNConfig*                               _config;
    HNPython*                               _python;
    HNDrivers*                              _drivers;
    HNNetworking*                           _networking;
    HNHistory*                              _history;
	HNHistoryDaemon*						_historyDaemon;

    size_t                                  _time_sync;
    QTimer*                                 _timerSync;

    static void                             p_sigHandler(int signal);
    void                                    p_stopOnError();
};

#endif
