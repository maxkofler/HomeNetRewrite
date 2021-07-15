#include "homenet.h"

#include <QCoreApplication>

void HomeNet::p_sigHandler(int sig){
    FUN();

    LOGI("Received signal: " + std::to_string(sig));

    if (sig == SIGINT){
        LOGI("HomeNet is shutting down...");
        QCoreApplication::quit();
    }
}
