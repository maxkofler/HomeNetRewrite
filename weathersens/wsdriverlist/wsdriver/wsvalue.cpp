#include "wsvalue.h"

WSValue::WSValue(){
    FUN();
    this->_loaded = false;
    this->_holdsValue = false;
}

bool WSValue::fromParsedBlock(ParseBlock block, uint lId, uint gId){
    FUN();

    //First of all check for the right size of the block
    if (block.getBlockCount() != 4){
        LOGE("Ammount of values to fetch from is not valid!");
        return false;
    }

    this->_type = block.getBlockAt(1);
    this->_name = block.getBlockAt(2);
    this->_unit = block.getBlockAt(3);
    this->_lId = lId;
    this->_gId = gId;

    LOGD("My local ID: " + std::to_string(lId));
    LOGD("My global ID: " + std::to_string(gId));


    this->_loaded = true;
    return true;
}
