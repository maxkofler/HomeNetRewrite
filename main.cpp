#include <iostream>

#include "log/log.h"
#include "homenet/homenet.h"

using namespace std;

Log* hlog;

int main(int argc, char** argv)
{
    hlog = new Log();
    FUN();

    HomeNet hn("/hn/hnconfig.txt");

    hn.startWS();

    return 0;
}
