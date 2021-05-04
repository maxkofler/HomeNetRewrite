#ifndef WSDRIVERLIST_H
#define WSDRIVERLIST_H

class WSDriverList;

#include "log/log.h"
#include "parser/parser.h"
#include "wsdriver/wsdriver.h"
#include "homenet/hnpython/hnpython.h"

#include <string>

class WSDriverList
{
public:
    WSDriverList(std::string driverListPath);

    /**
     * @brief importDriversPython
     * @param pyInst
     * @return
     */
    bool                        importPythonDrivers(HNPython* pyInst);

    bool                        callValues(std::string workDir);

private:
    Parser                      _listParser;
    std::vector<WSDriver>       _drivers;

    uint                        _nextGVId;      //This value holds the next global ID for a value
};

#endif // WSDRIVERLIST_H
