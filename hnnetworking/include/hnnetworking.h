#ifndef __HNNETWORKING_H__
#define __HNNETWORKING_H__

class HNNetworking;

#include "log.h"

#include "hnconfig.h"

#include <string>
#include <map>

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QAbstractSocket>

class HNNetworking : public QObject{
Q_OBJECT

public:
    HNNetworking(QObject* parent = 0);
    ~HNNetworking();

    bool                                    start(HNConfig& config);

private slots:
    void                                    onNewConnection();
    void                                    onReadyRead();
    void                                    onSocketStateChanged(QAbstractSocket::SocketState socketState);

private:
    int                                     _port;
    QTcpServer*                             _server;
    QList<QTcpSocket*>                      _sockets;
};

#endif
