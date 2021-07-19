#include "hnnetworking.h"

HNNetworking::HNNetworking(HNDrivers* drivers, QObject* parent){
    FUN();


    this->_drivers = drivers;

    this->_server = new QTcpServer(this);
}

HNNetworking::~HNNetworking(){
    FUN();

    if (this->_server->isListening()){
        LOGW("TCP Server is still listening, forcing quit!");
        this->_server->close();
    }
    
    delete this->_server;
}
