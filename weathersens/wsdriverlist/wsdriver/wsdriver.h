#ifndef WSDRIVER_H
#define WSDRIVER_H

class WSDriver;

#include <string>
#include <vector>

#include "log/log.h"
#include "parser/parseblock.h"
#include "homenet/hnpython/hnpython.h"
#include "wsvalue.h"

class WSDriver
{
public:
    WSDriver();
    ~WSDriver();

    /**
     * @brief fetch
     * @param blocks
     * @param pos
     * @return
     */
    bool                        fetch(std::vector<ParseBlock> blocks, size_t* pos, uint* nextGVId);

    void                        setPythonModule(PyModule mod){this->_driverPyModule = mod;}

    std::string                 name(){return this->_name;}
private:
    std::string                 _name;
    std::vector<WSValue>        _values;

    uint                        _nextLVId;

    PyModule                    _driverPyModule;
};

#endif // WSDRIVER_H
