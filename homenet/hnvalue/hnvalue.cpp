#include "hnvalue.h"

HNValue::HNValue(){
    FUN();
    this->_loaded = false;
    this->_holdsValue = false;
}

bool HNValue::fromParsedBlock(ParseBlock block, uint lId, uint gId){
    FUN();

    //First of all check for the right size of the block
    if (block.getBlockCount() != 4){
        LOGE("Ammount of values to fetch from is not valid!");
        return false;
    }

    this->_name = block.getBlockAt(1);
    this->_dtype = block.getBlockAt(2);
    this->_unit = block.getBlockAt(3);
    this->_lId = lId;
    this->_gId = gId;

    this->_loaded = true;
    return true;
}

std::string HNValue::toString(){
    std::string ret = "gId: [" + std::to_string(this->_gId) + "]\t lId: [" + std::to_string(this->_lId);
    ret += "]\t displayType:[" + this->_dtype;
    ret += "]\t valueType:[";
    ret.append(1, this->_vtype);
    ret += "]\t value:[" + this->_value + "]\t unit:[" + this->_unit + "]\t name:[" + this->_name + "]";
    return ret;
}
