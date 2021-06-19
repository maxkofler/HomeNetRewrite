#include "../hnnetworking.h"

#include <QHostAddress>

void HNNetworking::p_listen(){
    FUN();
    while(this->_listen){
        this->_server->waitForNewConnection(1000);

        //If there are pending connections, connect to them
        while (this->_server->hasPendingConnections()){
            QTcpSocket* newSock = this->_server->nextPendingConnection();
            LOGI("New connection from \"" + newSock->peerAddress().toString().toStdString() + "\"");
            HNClient* newClient = new HNClient(newSock, this);
            this->_clients.push_back(newClient);
        }
    }
}
