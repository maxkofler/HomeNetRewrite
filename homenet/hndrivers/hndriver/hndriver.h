#ifndef HNDRIVER_H
#define HNDRIVER_H

class HNDriver;

#include "log/log.h"
#include "homenet/hnvalue/hnvalue.h"
#include "parser/parseblock.h"

#include <vector>
#include <string>

class HNDriver{
public:
    HNDriver();
    ~HNDriver();

    bool                            fetchFromBlock(ParseBlock block);

    void                            addValue(HNValue v);
private:
    std::string                     _name;
    std::vector<HNValue>            _values;
};

#endif // HNDRIVER_H
