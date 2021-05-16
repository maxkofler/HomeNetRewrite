#include <iostream>
#include <string>
#include <signal.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "log/log.h"
#include "homenet/homenet.h"

Log hlog(Log::F);
HomeNet* hn;

void sighandler(int s){
    LOGI("Catched signal: " + std::to_string(s));
    hn->stopSyncLoop();
}

int main(int argc, char** argv)
{
    //hlog = new Log(Log::F);
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

        hn = new HomeNet("/etc/homenet/hnconfig.conf");

        signal(SIGINT, sighandler);

        hn->startSyncLoop();

        while(hn->isSyncLoopRunning())
            sleep(1);

        LOGI("Exiting...");

        delete hn;
    }

    LOGI("Bye!");
    sleep(1);
}
