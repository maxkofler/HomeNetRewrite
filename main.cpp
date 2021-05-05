#include <iostream>
#include <string>

#include "log/log.h"
#include "homenet/homenet.h"

Log* hlog;

int main(int argc, char** argv)
{
    hlog = new Log(Log::D);
    FUN();
    {
        //Plot some info about the program
        {
            std::string out = "";
            for(int i = 0; i < argc; i++){
                out += "[" + std::string(argv[i]) + "]";
            }
            LOGI("Starting HomeNet with args \"" + out + "\"...");
        }

        HomeNet hn("/hn/hnconfig.conf");

        hn.startWS();

        auto ws = hn.getWS();

        ws->callValues();

        LOGI("Quiting...");
    }
    using namespace std;
}
