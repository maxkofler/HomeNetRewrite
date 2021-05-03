#include <iostream>
#include <string>

#include "log/log.h"
#include "homenet/homenet.h"

Log* hlog;

int main(int argc, char** argv)
{
    hlog = new Log();
    FUN();

    //Plot some info about the program
    {
        std::string out = "";
        for(int i = 0; i < argc; i++){
            out += "[" + std::string(argv[i]) + "]";
        }
        LOGI("Starting HomeNet with args \"" + out + "\"...");
    }

    HomeNet hn("/hn/hnconfig.txt");

    hn.startWS();

    return 0;
}
