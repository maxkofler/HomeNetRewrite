#include <iostream>
#include <fstream>

#include "log.h"

#include "hnconfig.h"
#include "hndrivers.h"
#include "hnpython.h"

Log* hlog;

int main()
{
    hlog = new Log(Log::F, false);
    FUN();


    HNConfig config;

    config.parse("/etc/homenet/hnconfig.conf");

    HNPython python;
    python.startPython(false);

    HNDrivers drivers;
    if (!drivers.init(config, &python)){
        LOGE("Failed in initializing drivers!");
    }else{
        LOGI("Initialized drivers");
    }

    return 0;
}
