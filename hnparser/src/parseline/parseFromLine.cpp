#include "parseline.h"

int Parseline::parseFromLine(std::string line, char opener, char closer, bool acceptEmpty){
    FUN();

    //Clear the current vector
    this->_blocks.clear();

    size_t pos1 = 0;
    size_t pos2 = 0;

    while(true){
        pos1 = line.find(opener, pos2);
        pos2 = line.find(closer, pos1);

        //If a block was found
        if (pos1 != std::string::npos && pos2 != std::string::npos){
            if (!line.substr(pos1+1, pos2-pos1-1).empty() || acceptEmpty){
                this->_blocks.push_back(line.substr(pos1+1, pos2-pos1-1));
                LOGF("Adding block \"" + this->_blocks.back() + "\"");
            }
        }else
            break;
    }

    return this->_blocks.size();
}
