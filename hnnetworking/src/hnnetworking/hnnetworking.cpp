#include "hnnetworking.h"

HNNetworking::HNNetworking(HNDrivers* drivers, HNHistory* history, QObject* parent){
    FUN();


    this->_drivers = drivers;
    this->_history = history;

    this->_server = new QTcpServer(this);
}

HNNetworking::~HNNetworking(){
    FUN();

    //Close ALL client connections
    for (QTcpSocket* sock : this->_sockets){
        if (sock->isOpen()){
            LOGW("Closing connection to " + sock->peerAddress().toString().toStdString());
            sock->close();
        }
    }

    LOGD("Closing server...");
    this->_server->close();
    
    delete this->_server;
}
