#include "wsconfig.h"

WSConfig::WSConfig(std::string configPath){
    FUN();
    this->_parser.parseFile(configPath);
}

std::string WSConfig::getConfig(std::string name){
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
