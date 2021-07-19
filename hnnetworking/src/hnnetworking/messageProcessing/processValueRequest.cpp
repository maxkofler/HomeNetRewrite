#include "hnnetworking.h"

bool HNNetworking::processValueRequest(std::string message, QTcpSocket* sender){
    FUN();

    LOGD("The value request is: \"" + message + "\"");

    char mode = message[0];
    message = message.substr(1, message.length()-1);

    switch(mode){
    case 'q':   //Value query
                {
                size_t valueIndex = stoi(message);
                LOGI("Requesting value #" + std::to_string(valueIndex));
                if (!this->_drivers->ok()){
                    LOGE("HNDrivers instance is not ok!");
                    break;
                }
                std::vector<hnvalue_t*>* valuesVector = this->_drivers->getValues();
                if (valueIndex < valuesVector->size()){
                    hnvalue_t* value = valuesVector->at(valueIndex);
                    std::string retMsg = "<" + value->name + "><" + value->value + "><" + value->unit + ">\n";
                    sender->write(retMsg.c_str());
                    sender->flush();
                    sender->waitForBytesWritten(retMsg.length());
                }else{
                    std::string retMsg = "Error: Index is out of bounds!";
                    sender->write(retMsg.c_str(), retMsg.length());
                }
                break;
                }

    case 'h':   //Value history
                LOGI("Requesting history of value #" + message);
                break;
    }

    return true;
}
