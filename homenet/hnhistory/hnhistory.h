#ifndef HNHISTORY_H
#define HNHISTORY_H

class HNHistory;

#include "log/log.h"
#include "parser/parser.h"

#include "homenet/hnvalue/hnvalue.h"

#include <string>

class HNHistory
{
public:
    HNHistory(std::string historyDir);
    ~HNHistory();

    /**
     * @brief Creates a history entry for a value
     * @param driverName        The name of the driver that contains this value
     * @param value             A reference to the value
     * @return
     */
    bool                        createValueEntry(std::string driverName, HNValue& value);
private:
    std::string                 _historyDir;
    Parser*                     _historyParser;
};

#endif // HNHISTORY_H
