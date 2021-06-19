#include "hnnetworking.h"

HNNetworking::HNNetworking(){
    FUN();
    LOGD("Initializing networking submodule");

    this->_server = new QTcpServer();
    connect(this->_server, &QTcpServer::newConnection, this, &HNNetworking::p_sl_newConnection);
    if (this->_server->listen(QHostAddress::Any, 8080)){
        LOGI("Server is listening...");
    }else{
        LOGE("Server failed to start listening for connections");
    }
}
