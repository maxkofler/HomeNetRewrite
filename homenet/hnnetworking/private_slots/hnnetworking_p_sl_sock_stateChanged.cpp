#include "../hnnetworking.h"

void HNNetworking::p_sl_sock_stateChanged(QAbstractSocket::SocketState socketState){
    FUN();

    //If the socket has closed, remove it
    if (socketState == QAbstractSocket::UnconnectedState){
        //Get an instance of the socket
        QTcpSocket* socket = static_cast<QTcpSocket*>(QObject::sender());
        //And remove the instance
        this->_sockets.removeOne(socket);
    }
}
