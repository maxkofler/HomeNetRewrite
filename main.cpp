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

Log hlog(Log::I, true);
HomeNet* hn;

void sighandler(int s){
    switch(s){
        case 2: LOGE("Received SIGINT, shutting down normally...");
                hn->stopSyncLoop();
        break;

        //SIGABRT
        case 6: LOGE("Received SIGABRT, trying to shut down normally...");
                hn->stopSyncLoop();
        break;
    }

    LOGI("Catched signal: " + std::to_string(s));
    hn->stopSyncLoop();
}

int main(int argc, char** argv)
{
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

        //Try to get the config path from the command line...
        if (argc >= 2){
            hn = new HomeNet(argv[1]);
        }else{
            LOGW("Could not fetch config path from command line, falling back to default: /etc/homenet/hnconfig.conf!");
            hn = new HomeNet("/etc/homenet/hnconfig.conf");
        }

        //Register the handler for CTRL-C
        signal(SIGINT, sighandler);
        signal(SIGABRT, sighandler);
        signal(SIGKILL, sighandler);

        //Start the sync loop to constantly sync all the values
        hn->startSyncLoop();

        //Wait for the syncloop to join (after CTRL-C)
        while(hn->isSyncLoopRunning())
            sleep(1);

        //Quit HomeNet
        LOGI("Exiting...");
        delete hn;
    }

    LOGI("Bye!");
}
