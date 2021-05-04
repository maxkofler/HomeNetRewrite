#ifndef WSDRIVER_H
#define WSDRIVER_H

class WSDriver;

#include <string>
#include <vector>

#include "log/log.h"
#include "parser/parseblock.h"
#include "wsvalue.h"

class WSDriver
{
public:
    WSDriver();


    /**
     * @brief fetch
     * @param blocks
     * @param pos
     * @return
     */
    bool                        fetch(std::vector<ParseBlock> blocks, size_t* pos, uint* nextGVId);
private:
    std::string                 _name;
    std::vector<WSValue>        _values;

    uint                        _nextLVId;
};

#endif // WSDRIVER_H
