#include "hnconfig.h"

HNConfig::HNConfig(std::string fPath){
    FUN();
    this->_parser.parseFile(fPath);
}

std::string HNConfig::getConfig(std::string name){
    FUN();
    std::vector<ParseBlock> confBlocks = this->_parser.getVector();
    std::string ret;

    for (auto i : confBlocks){
        if (i.getBlocks().at(0) == name){
            return i.getBlocks().at(1);
        }
    }

    LOGE("Could not find a config with the name \"" + name + "\"!");

    return ret;
}
