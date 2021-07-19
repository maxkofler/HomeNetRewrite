#include "hnnetworking.h"
#include "homenet_status.h"

#include <QCoreApplication>

extern homenet_status stateHomeNet;

bool HNNetworking::processSystemRequest(std::string message, QTcpSocket* sender){
    FUN();

    LOGD("The system request is: \"" + message + "\"");

    if (message == "quit"){
        //Quit HomeNet
        LOGI("Exiting HomeNet from request over network");
        stateHomeNet.running = false;
        QCoreApplication::exit();
    }

    if (message == "restart"){
        //Quit HomeNet
        LOGI("Exiting HomeNet from request over network");
        stateHomeNet.running = true;
        QCoreApplication::exit();
    }

    return true;
}
