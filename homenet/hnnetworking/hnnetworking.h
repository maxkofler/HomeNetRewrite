#ifndef HNNETWORKING_H
#define HNNETWORKING_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

#include <vector>

#include "log/log.h"

class HNNetworking : public QObject {
Q_OBJECT
public:
    HNNetworking();

private slots:
    void                                    p_sl_newConnection();
    void                                    p_sl_sock_stateChanged(QAbstractSocket::SocketState socketState);
    void                                    p_sl_sock_readyRead();

private:
    QTcpServer*                             _server;
    QList<QTcpSocket*>                      _sockets;
};

#endif // HNNETWORKING_H
