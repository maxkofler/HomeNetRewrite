#include <iostream>

#include "log/log.h"

#include "parser/parser.h"

using namespace std;

Log* log;

int main()
{
    log = new Log();
    FUN();
    Parser parser;
    parser.parseFile("Gaming");
    return 0;
}
