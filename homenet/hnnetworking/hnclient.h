#ifndef HNCLIENT_H
#define HNCLIENT_H

class HNClient;

#include <thread>
#include <string>

#include <QTcpSocket>

#include "log/log.h"
#include "hnnetworking.h"

class HNClient
{
public:
    HNClient(QTcpSocket* sock, HNNetworking* parent);

private:
    HNNetworking*                   _hnnetworking;

    QTcpSocket*                     _sock;
    std::thread*                    _th_waitRead;
    bool                            _listenRead;
    void                            p_listenRead();

    std::string                     _peerName;
};

#endif // HNCLIENT_H
