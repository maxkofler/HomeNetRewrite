#include "hnparser.h"

HNParser::HNParser(){
    FUN();
}

HNParser::~HNParser(){
    FUN();

    //Delete all lines
    for (auto* i : this->_lines){
        delete i;
    }
}
