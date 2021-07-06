#include "hnnetworking.h"

void HNNetworking::onReadyRead(){
    FUN();

    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());

    std::string msg = sender->readAll().toStdString();

    LOGF("Receiving from " + sender->peerAddress().toString().toStdString() + ": " + msg);

    sender->write(msg.c_str(), msg.length());
}
