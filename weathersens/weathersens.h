#ifndef WEATHERSENS_H
#define WEATHERSENS_H

class Weathersens;

#include "log/log.h"
#include "wsconfig/wsconfig.h"
#include "homenet/homenet.h"

#include <string>

class Weathersens
{
public:
    Weathersens(std::string wsConfigPath, HomeNet* hn);

private:
    bool                    _ok;
    HomeNet*                _hn;
    WSConfig*               _config;
};

#endif // WEATHERSENS_H
