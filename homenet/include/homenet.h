#ifndef __HOMENET_H__
#define __HOMENET_H__

class HomeNet;

#include <QObject>

#include "log.h"

#include "hndrivers.h"
#include "hnconfig.h"
#include "hnpython.h"

class HomeNet : public QObject{
    Q_OBJECT

public:
    HomeNet(QObject* parent = 0) : QObject(parent){
        FUN();

        this->_config = new HNConfig();
        this->_python = new HNPython();
        this->_drivers = new HNDrivers();
    }
    ~HomeNet();

public slots:
    void                                    start();

signals:
    void                                    stop();

private:
    HNConfig*                               _config;
    HNPython*                               _python;
    HNDrivers*                              _drivers;
};

#endif