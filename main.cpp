#include <iostream>
#include <fstream>

#include "log.h"

#include "hnconfig.h"

Log* hlog;

int main()
{
    hlog = new Log(Log::F, false);
    FUN();


    HNConfig config;

    config.parse("/etc/homenet/hnconfig.conf");

    config.getConfig("driverdir");

    return 0;
}
