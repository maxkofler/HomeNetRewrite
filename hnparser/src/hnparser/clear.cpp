#include "hnparser.h"

void HNParser::clear(){
    FUN();

    LOGD("Clearing parsed cache");

    for (auto* i : this->_lines){
        delete i;
    }

    this->_lines.clear();
}
