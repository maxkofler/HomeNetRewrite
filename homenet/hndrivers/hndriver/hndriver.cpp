#include "hndriver.h"

HNDriver::HNDriver(){
    FUN();
    this->_moduleLoaded = false;
}

HNDriver::~HNDriver(){

}

bool HNDriver::fetchFromBlock(ParseBlock block){
    FUN();
    if (block.getBlockCount() == 2)
        this->_name = block.getBlockAt(1);
    else{
        LOGE("Invalid block count!");
        return false;
    }
    return true;
}

void HNDriver::addValue(HNValue v){
    FUN();
    this->_values.push_back(v);
}

std::string HNDriver::getOverview(){
    FUN();
    std::string ret = "[driver]-> \"" + this->_name + "\":\n";
    for (auto& i : this->_values){
        ret += "\t[value]-> " + i.toString() + "\n";
    }
    return ret;
}
