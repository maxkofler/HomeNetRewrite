#include "../hnnetworking.h"

void HNNetworking::p_sl_newConnection(){
    FUN();

    LOGD("New connection requested");

    //Create new socket instance
    QTcpSocket* newSock = this->_server->nextPendingConnection();

    LOGI("New connection from \"" + newSock->peerAddress().toString().toStdString() + "\"");

    //Connect signals for controlling the socket and its data
    connect(newSock, &QTcpSocket::readyRead, this, &HNNetworking::p_sl_sock_readyRead);
    connect(newSock, &QTcpSocket::stateChanged, this, &HNNetworking::p_sl_sock_stateChanged);

    //Add it to the list of sockets
    this->_sockets.push_back(newSock);

    newSock->write(QByteArray::fromStdString("Hi!"));
}
