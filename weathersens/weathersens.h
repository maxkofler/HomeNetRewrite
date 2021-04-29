#ifndef WEATHERSENS_H
#define WEATHERSENS_H

class Weathersens;

#include "log/log.h"
#include "homenet/homenet.h"

#include <string>

class Weathersens
{
public:
    Weathersens(std::string wsConfigPath, HomeNet* hn);

private:
    HomeNet*            _hn;
};

#endif // WEATHERSENS_H
