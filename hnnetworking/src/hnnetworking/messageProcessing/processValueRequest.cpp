#include "hnnetworking.h"

bool HNNetworking::processValueRequest(std::string message){
    FUN();

    LOGD("The value request is: \"" + message + "\"");

    char mode = message[0];
    message = message.substr(1, message.length()-1);

    switch(mode){
    case 'q':   //Value query
                LOGI("Requesting value #" + message);
                break;

    case 'h':   //Value history
                LOGI("Requesting history of value #" + message);
                break;
    }

    return true;
}
