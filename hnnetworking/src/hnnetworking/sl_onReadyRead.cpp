#include "hnnetworking.h"

void HNNetworking::onReadyRead(){
    FUN();

    QTcpSocket* sender = static_cast<QTcpSocket*>(QObject::sender());

    std::string msg = sender->readAll().toStdString();

    LOGI("Receiving from " + sender->peerAddress().toString().toStdString() + ": " + msg);

    processMessage(msg, sender);
}
