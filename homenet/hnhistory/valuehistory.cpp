#include "hnhistory.h"

#include <chrono>
#include <filesystem>

bool HNHistory::createValueEntry(std::string driverName, HNValue &value){
    FUN();

    //Check for parser instance
    if (this->_historyParser == nullptr){
        LOGE("Parser instance is not available!");
        return false;
    }

    {
        std::string hD = this->_historyDir + "/" + driverName;
        if (!std::filesystem::create_directories(hD)){
        }
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
