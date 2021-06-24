#include "parseline.h"


std::string Parseline::toParseLine(char opener, char closer){
    FUN();

    std::string ret = "";
    for (std::string& i : this->_blocks){
        ret += opener + i + closer;
    }

    return ret;
}
