#include "../hnclient.h"

#include <QHostAddress>

void HNClient::p_listenRead(){
    FUN();

    while(this->_listenRead){
        this->_sock->waitForReadyRead();
        if (this->_sock->state() == QAbstractSocket::UnconnectedState){
            LOGI("Socket to \"" + this->_peerName + "\" closed");
            this->_listenRead = false;
            this->_hnnetworking->_clients.removeOne(this);
            LOGI("Remaining connected clients: " + std::to_string(this->_hnnetworking->_clients.size()));
        }else{
            while(this->_sock->isReadable() && this->_sock->size() > 0){
                LOGF(   "Incoming message from \"" + this->_peerName
                        + "\" : " + this->_sock->readAll().toStdString());
            }
        }
    }
}
