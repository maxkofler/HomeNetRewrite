#include "hnnetworking.h"

bool HNNetworking::processMessage(std::string message, QTcpSocket* sender){
    FUN();
    std::string fStr = "processing message: ";

    {   //Strip all newlines
        std::string nStr = "";
        for (char i : message){
            if (i != '\n'){
                nStr += i;
            }
        }
    }

    {   //Check for the '@' at the beginning and strip it, if it isn't present this message is garbage        
        LOGD(fStr + "Checking for '@', length of message: " + std::to_string(message.length()));
        size_t posAt = message.find('@');

        if (posAt == std::string::npos){
            LOGE(fStr + "This message does not contain an '@', it will be ignored!");
            return false;
        }

        if (message.length() <= 2){
            LOGE(fStr + "Message is too short!");
            std::string retMsg = "<E><Message does not contain any operation!>\n";
            sender->write(retMsg.c_str());
            sender->flush();
            sender->waitForBytesWritten(retMsg.length());
            return false;
        }

        message = message.substr(posAt+1, message.length()-posAt-2);

        LOGD(fStr + "Message after stripping: \"" + message + "\"");
    }

    {   //Switch to the intended action:
        char operation = message[0];
        message = message.substr(1, message.length()-1);
        switch(operation){
            case 'v':   //A value operation is requested
                        LOGD(fStr + "The message is a value operation");
                        return processValueRequest(message, sender);

            case 's':   //A system operation is requested
                        LOGD(fStr + "The message is a system operation");
                        return processSystemRequest(message, sender);
        }
    }

    return true;
}
