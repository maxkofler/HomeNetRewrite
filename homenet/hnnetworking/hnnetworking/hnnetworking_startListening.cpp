#include "../hnnetworking.h"

void HNNetworking::startListening(int port){
    FUN();

    this->_server->listen(QHostAddress::Any, port);

    this->_listen = true;
    this->_t_listen = new std::thread(&HNNetworking::p_listen, this);
}
