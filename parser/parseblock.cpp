#include "parseblock.h"

ParseBlock::ParseBlock(){
    FUN();
}

int ParseBlock::parseFromLine(std::string line){
    FUN();


    size_t pos1 = 0;
    size_t pos2 = 0;

    char open = '<';
    char close = '>';

    while (true){
        pos1 = line.find(open, pos2);
        pos2 = line.find(close, pos1);

        //Check whether we found the tokens
        if (pos1 != std::string::npos && pos2 != std::string::npos){
            this->_blocks.push_back(line.substr(pos1+1, pos2-pos1-1));
        }else
            break;
    }

    return this->_blocks.size();
}

std::string ParseBlock::toString(){
    FUN();
    std::string ret = "";
    for (size_t i = 0; i < this->_blocks.size(); i++){
        ret += "[" + this->_blocks.at(i) + "]";
    }
    return ret;
}
