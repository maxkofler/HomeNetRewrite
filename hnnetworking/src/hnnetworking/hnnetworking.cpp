#include "hnnetworking.h"

HNNetworking::HNNetworking(HNDrivers* drivers, HNHistory* history, QObject* parent){
    FUN();


    this->_drivers = drivers;
    this->_history = history;

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
