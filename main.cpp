#include <iostream>
#include <fstream>

#include "log.h"

#include "hnconfig.h"
#include "hndrivers.h"
#include "hnpython.h"

Log* hlog;

int main()
{
    hlog = new Log(Log::F, true);
    FUN();


    HNConfig config;

    config.parse("/etc/homenet/hnconfig.conf");

    HNPython python;
    python.startPython();

    HNDrivers drivers;
    if (!drivers.init(config, &python)){
        LOGE("Failed in initializing drivers!");
    }else{
        LOGI("Initialized drivers");
    }

    if(!drivers.loadDrivers()){
        LOGE("Failed loading drivers!");
    }else{
        LOGI("Loaded drivers");
    }

    return 0;
}
