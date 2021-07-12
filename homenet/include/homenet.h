#ifndef __HOMENET_H__
#define __HOMENET_H__

class HomeNet;

#include <QObject>
#include <QTimer>

#include "log.h"

#include "hndrivers.h"
#include "hnconfig.h"
#include "hnpython.h"
#include "hnnetworking.h"
#include "hnhistory.h"

class HomeNet : public QObject{
    Q_OBJECT

public:
    HomeNet(QObject* parent = 0) : QObject(parent){
        FUN();

        this->_config = new HNConfig();
        this->_python = new HNPython();
        this->_drivers = new HNDrivers();
        this->_networking = new HNNetworking(this);
        this->_history = new HNHistory();
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

    size_t                                  _time_sync;
    QTimer*                                 _timerSync;
};

#endif
