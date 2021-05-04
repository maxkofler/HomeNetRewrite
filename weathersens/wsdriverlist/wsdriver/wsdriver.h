#ifndef WSDRIVER_H
#define WSDRIVER_H

class WSDriver;

#include <string>
#include <vector>

#include "log/log.h"
#include "parser/parser.h"
#include "wsvalue.h"

class WSDriver
{
public:
    WSDriver();

    /**
     * @brief Fetches the driver data from the parser
     * @param parser            The parser to fetch from
     * @return
     */
    bool                        fetch(Parser* parser);
private:
    std::string                 _name;
    std::vector<WSValue>        _values;
};

#endif // WSDRIVER_H
