#include "hnparser.h"

void HNParser::clear(){
    FUN();

    LOGD("Clearing parsed cache");

    this->_lines.clear();
}
