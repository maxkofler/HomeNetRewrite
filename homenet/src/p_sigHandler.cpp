#include "homenet.h"
#include "homenet_status.h"

extern homenet_status stateHomeNet;

#include <QCoreApplication>

void HomeNet::p_sigHandler(int sig){
    FUN();

    LOGI("Received signal: " + std::to_string(sig));

    if (sig == SIGINT){
        LOGI("HomeNet is shutting down...");
        stateHomeNet.running = false;
        QCoreApplication::quit();
    }
}
