#include "hnnetworking.h"

bool HNNetworking::processHelpRequest(std::string message, QTcpSocket* sender){
    std::string retMsg = "-----NETWORK COMMANDS HELP-----\n";

    retMsg += "valid modes:\n";
    retMsg += "\tv\tValue request\n";
    retMsg += "\t\tq<id>\t\tRequest current value of value <id>\n";
    retMsg += "\t\th<id>\t\tRequest history of value <id>\n";
    retMsg += "\t\th<id>,<lb>\tRequest history of value <id> with the lookback of <lb> seconds\n";
    
    retMsg += "\n\ts\tSystem request:";
    retMsg += "\tCommand added directly to 's': \"@squit\" -> quit\n";
    retMsg += "\t\tquit\tStops the HomeNet server\n";
    retMsg += "\t\trestart\tRestarts the HomeNet server\n";

    retMsg += "\n\th\tHelp request (This page)\n";

    sender->write(retMsg.c_str());
    sender->flush();
    sender->waitForBytesWritten(retMsg.length());

    return true;
}