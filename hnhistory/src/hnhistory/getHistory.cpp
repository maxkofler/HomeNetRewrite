#include "hnhistory.h"

std::string HNHistory::getHistory(time_t lookback){
    FUN();
    std::string ret;
    ret.clear();

    auto history = this->_parser.getLines();
    size_t indexStartLookback = history.size();


    {   //Search for beginning of the lookback window
        time_t firstEntryTime = time(0) - lookback;
        time_t nextEntryTime = time(0);
        LOGI("Requested history back to " + std::to_string(firstEntryTime) + " UNIX time!");

        while (nextEntryTime > firstEntryTime && indexStartLookback != 0){
            indexStartLookback--;
            LOGD(   "Checking history time block: " + history.at(indexStartLookback).getBlock(0) + 
                    " > " + std::to_string(firstEntryTime));
            try{
                nextEntryTime = stoi(history.at(indexStartLookback).getBlock(0));
            }catch(std::out_of_range& e){
                LOGE("Time request is out of range: " + std::string(e.what()));
                return ret;
            }
            
        }
    }

    HNParser outParser; 
    {   //Now copy the lookback window to a new parser
        for (; indexStartLookback < history.size(); indexStartLookback++){
            outParser.append(history.at(indexStartLookback));
        }
    }

    {   //Move all data into a string
        std::stringstream strStream;
        outParser.writeToStream(strStream);

        ret = strStream.str();
    }

    return ret;
}

std::string HNHistory::getHistory(){
    FUN();
    std::string ret;

    auto history = this->_parser.getLines();
    size_t indexStartLookback = 0;

    HNParser outParser; 
    {   //Now copy the lookback window to a new parser
        for (; indexStartLookback < history.size(); indexStartLookback++){
            outParser.append(history.at(indexStartLookback));
        }
    }

    {   //Move all data into a string
        std::stringstream strStream;
        outParser.writeToStream(strStream);

        ret = strStream.str();
    }

    return ret;
}