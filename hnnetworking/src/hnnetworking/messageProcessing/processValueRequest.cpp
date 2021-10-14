#include "hnnetworking.h"

#include <sstream>

void answerWrongArgument(QTcpSocket* socket);

bool HNNetworking::processValueRequest(std::string message, QTcpSocket* sender){
    FUN();

    LOGD("The value request is: \"" + message + "\"");

    bool messageHasArgument = false;
    char mode = message[0];
    if (message.length() >= 2){
        message = message.substr(1, message.length()-1);
        messageHasArgument = true;
    }

    switch(mode){
    case 'q':   //Value query
                {
                if (!messageHasArgument){
                    LOGE("Value query id is invalid!");
                    answerWrongArgument(sender);
                    break;
                }
                size_t valueIndex = stoi(message);
                LOGI("Requesting value #" + std::to_string(valueIndex));
                if (!this->_drivers->ok()){
                    LOGE("HNDrivers instance is not ok!");
                    break;
                }
                std::vector<hnvalue_t*>* valuesVector = this->_drivers->getValues();
                if (valueIndex < valuesVector->size()){
                    std::string response = valuesVector->at(valueIndex)->toTransmissionString() + "\n<eot>\n";
                    sender->write(response.c_str());
                    sender->flush();
                    sender->waitForBytesWritten(response.length());
                }else{
                    std::string retMsg = "<E><ValueID out of bounds!>\n<eot>\n";
                    sender->write(retMsg.c_str());
                    sender->flush();
                    sender->waitForBytesWritten(retMsg.length());
                }
                break;
                }

    case 'a':   //Query of all values
            {
                std::vector<hnvalue_t*>* valuesVector = this->_drivers->getValues();

                std::string retMsg = "";
                for (hnvalue_t* curValue : *valuesVector){
                    retMsg += curValue->toTransmissionString() + "\n";
                }

                retMsg += "<eot>\n";

                sender->write(retMsg.c_str());
                sender->flush();
                sender->waitForBytesWritten(retMsg.length());
                break;
            }


    case 'h':   //Value history
            {
                if (!messageHasArgument){
                    LOGE("Value query id is invalid!");
                    answerWrongArgument(sender);
                    break;
                }
                size_t valueID;
                time_t lookback = 0;
                //Check if the request includes a lookback window
                if (message.find(',') == std::string::npos){
                    //No lookback window
                    valueID = stoi(message);
                }else{
                    std::stringstream sStream(message);
                    std::vector<std::string> sVector;
                    std::string buf;

                    while(std::getline(sStream, buf, ',')){
                        sVector.push_back(buf);
                    }

                    if (sVector.size() >= 2){
                        try{
                            valueID = stoi(sVector.at(0));
                            lookback = stoi(sVector.at(1));
                        }catch(std::out_of_range& e){
                            LOGE("Value lookback is out of range: " + std::string(e.what()));

                            std::string retMsg = "<E><Value lookback is out of range: " + std::string(e.what()) + ">\n<eot>\n";
                            sender->write(retMsg.c_str());
                            sender->flush();
                            sender->waitForBytesWritten(retMsg.length());
                            break;
                        }
                        

                        if (lookback == 0){
                            LOGE("Lookback can not be 0!");

                            std::string retMsg = "<E><Lookback can not be 0!>\n<eot>\n";
                            sender->write(retMsg.c_str());
                            sender->flush();
                            sender->waitForBytesWritten(retMsg.length());
                            break;
                        }
                    }else{
                        LOGE("Invalid value request: \"" + message + "\"");
                        break;
                    }
                }

                LOGI("Requesting history of value #" + std::to_string(valueID));

                this->_history->read(*this->_drivers->getValues()->at(valueID));

                std::string retMsg;

                if(lookback == 0)
                    retMsg = this->_history->getHistory();
                else
                    retMsg = this->_history->getHistory(lookback);

                sender->write(retMsg.c_str());
                sender->flush();
                sender->waitForBytesWritten(retMsg.length());
                break;
            }
                

    default:
            {
                std::string retMsg = "<E><Not a valid value request!>\n<eot>\n";
                sender->write(retMsg.c_str());
                sender->flush();
                sender->waitForBytesWritten(retMsg.length());
            }
    }

    return true;
}


void answerWrongArgument(QTcpSocket* sender){
    std::string retMsg = "<E><Invalid argument!>\n<eot>\n";
    sender->write(retMsg.c_str());
    sender->flush();
    sender->waitForBytesWritten(retMsg.length());
}