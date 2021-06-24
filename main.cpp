#include <iostream>
#include <fstream>

#include "log.h"

#include "hnparser.h"

Log* hlog;

int main()
{
    hlog = new Log(Log::F, false);

    HNParser parser;

    std::ifstream file;
    file.open("/etc/homenet/hnconfig.conf");
    if (file.is_open()){
        parser.parseStream(file);           
    }else
        LOGE("File was not found!");
    file.close();
    
    std::ofstream outFile;
    outFile.open("gaming.conf");
    parser.writeToStream(outFile);

    outFile.close();

    FUN();
    LOGD("Hello");
    return 0;
}
