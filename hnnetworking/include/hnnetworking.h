#ifndef __HNNETWORKING_H__
#define __HNNETWORKING_H__

class HNNetworking;

#include "log.h"

#include "hnconfig.h"
#include "hndrivers.h"
#include "hnhistory.h"

#include <string>
#include <map>

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QAbstractSocket>

class HNNetworking : public QObject{
Q_OBJECT

public:
    HNNetworking(HNDrivers* drivers, HNHistory* history, QObject* parent = 0);
    ~HNNetworking();
    bool                                    start(HNConfig& config);

private slots:
    void                                    onNewConnection();
    void                                    onReadyRead();
    void                                    onSocketStateChanged(QAbstractSocket::SocketState socketState);

private:
    int                                     _port;

    HNDrivers*                              _drivers;
    HNHistory*                              _history;

    QTcpServer*                             _server;
    QList<QTcpSocket*>                      _sockets;


    /**
     * @brief   Processes the message that is coming in from the network
     * @param   message
     */
    bool                                    processMessage(std::string message, QTcpSocket* sender);

    /**
     * @brief   Gets used if the request is regarding a value
     * @param   message
     */
    bool                                    processValueRequest(std::string message, QTcpSocket* sender);

    /**
     * @brief   Gets used if the request is regarding the system (OS and HomeNet)
     * @param   message
     */
    bool                                    processSystemRequest(std::string message, QTcpSocket* sender);

    /**
     * @brief   Gets used if the request is regarding help
     * @param   message
     */
    bool                                    processHelpRequest(std::string message, QTcpSocket* sender);

};

#endif
