#include "hnnetworking.h"

bool HNNetworking::start(HNConfig& config){
    FUN();

    std::string fStr = "Starting TCP server: ";

    {
        LOGI(fStr + "Getting configs");

        this->_port = std::stoi(config.getConfig("port").back());
    }

    {
        LOGI(fStr + "Connecting signals and slots");

        connect(this->_server, &QTcpServer::newConnection, this, &HNNetworking::onNewConnection);
    }

    {
        LOGI(fStr + "Starting to listen on port " + std::to_string(this->_port));

        if (!this->_server->listen(QHostAddress::Any, this->_port)){
            LOGE(fStr + "Failed to start listening on port " + std::to_string(this->_port) + "!");
            return false;
        }
    }

    return true;
}
