#include "hnparser.h"

void HNParser::append(Parseline line){
    FUN();

    Parseline* newLine = new Parseline(line);

    this->_lines.push_back(newLine);
}
