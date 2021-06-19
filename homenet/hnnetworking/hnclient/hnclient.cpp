#include "../hnclient.h"

HNClient::HNClient(QTcpSocket* sock, HNNetworking* networking){
    FUN();
    this->_hnnetworking = networking;
    this->_sock = sock;

    this->_peerName = this->_sock->peerAddress().toString().toStdString();

    this->_listenRead = true;
    this->_th_waitRead = new std::thread(&HNClient::p_listenRead, this);
}
