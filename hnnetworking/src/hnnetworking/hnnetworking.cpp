#include "hnnetworking.h"

HNNetworking::HNNetworking(QObject* parent){
    FUN();

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