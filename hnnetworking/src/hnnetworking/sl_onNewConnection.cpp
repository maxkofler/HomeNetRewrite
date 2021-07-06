#include "hnnetworking.h"

void HNNetworking::onNewConnection(){
    FUN();

    QTcpSocket* newSock = this->_server->nextPendingConnection();

    LOGI(   "New connection from " + newSock->peerAddress().toString().toStdString() + ", sockets connected in total: " +
            std::to_string(this->_sockets.size()+1));

    connect(newSock, &QTcpSocket::readyRead, this, &HNNetworking::onReadyRead);
    connect(newSock, &QTcpSocket::stateChanged, this, &HNNetworking::onSocketStateChanged);

    this->_sockets.push_back(newSock);
}
