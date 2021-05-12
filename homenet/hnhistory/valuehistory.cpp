#include "hnhistory.h"

#include <chrono>

bool HNHistory::createValueEntry(std::string driverName, HNValue &value){
    FUN();

    //Check for parser instance
    if (this->_historyParser == nullptr){
        LOGE("Parser instance is not available!");
        return false;
    }

    std::string histPath = this->_historyDir + "/" + driverName + "/" + value.name() + ".hnhist";

    ParseBlock blk;

    std::string t;
    t.push_back(value.valueType());

    //First of all the timestamp, then the valuetype and then the value
    blk.append(t);
    blk.append(std::to_string(value.queryTime()));
    blk.append(value.value());

    return this->_historyParser->appendToFile(histPath, blk);
}
