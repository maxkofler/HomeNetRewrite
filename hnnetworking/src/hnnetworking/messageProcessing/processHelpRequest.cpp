#include "hnnetworking.h"

bool HNNetworking::processHelpRequest(std::string message, QTcpSocket* sender){
    std::string retMsg = "-----NETWORK COMMANDS HELP-----\n";

    retMsg += "valid modes:\n";
    retMsg += "\tv\tValue request\n";
    retMsg += "\ts\tSystem request\n";
    retMsg += "\th\tHelp request\n";

    sender->write(retMsg.c_str());
    sender->flush();
    sender->waitForBytesWritten(retMsg.length());

    return true;
}