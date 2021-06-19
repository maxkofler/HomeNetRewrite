#include "../hnnetworking.h"

HNNetworking::HNNetworking(){
    FUN();
    LOGD("Initializing networking submodule");

    this->_server = new QTcpServer();
}
