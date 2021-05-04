#include "wsdriver.h"

WSDriver::WSDriver(){
    FUN();
    this->_nextLVId = 0;
}

bool WSDriver::fetch(std::vector<ParseBlock> blocks, size_t* pos, uint* nextGVId){
    FUN();

    if (blocks.at(*pos).getBlockAt(0) != "driver"){
        LOGE("Tried to fetch a line not containing a driver!");
        return false;
    }

    (*pos)++;

    while (blocks.at(*pos).getBlockAt(0) != "/driver"){
        WSValue nvalue;
        if(nvalue.fromParsedBlock(blocks.at(*pos), this->_nextLVId, *nextGVId)){
            this->_values.push_back(nvalue);
            this->_nextLVId++;
            (*nextGVId)++;
            (*pos)++;
        }else{
            LOGE("Failed parsing a value, stopping parse...");
            return false;
        }
    }

    LOGD("Fetched one driver!");
    return true;
}
