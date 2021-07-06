#include "hnnetworking.h"

void HNNetworking::onSocketStateChanged(QAbstractSocket::SocketState socketState){
    FUN();

    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());

    if (socketState == QAbstractSocket::SocketState::UnconnectedState){
        LOGI(   "Socket of " + sender->peerAddress().toString().toStdString() + " closed, remaining sockets: " +
                std::to_string(this->_sockets.size()-1));
        this->_sockets.removeOne(sender);
    }
}
