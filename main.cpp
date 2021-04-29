#include <iostream>

#include "log/log.h"
#include "homenet/homenet.h"

using namespace std;

Log* log;

int main()
{
    log = new Log();
    FUN();

    HomeNet hn("/hn/hnconfig.txt");

    hn.startWS();

    return 0;
}
