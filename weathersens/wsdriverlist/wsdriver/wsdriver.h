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

    /**
     * @brief Sets the python module and the python instance
     * @param mod
     * @param pyInst
     */
    void                        setPythonModule(PyModule mod, HNPython* pyInst){this->_driverPyModule = mod;
                                                                                this->_pyInstance = pyInst;}

    /**
     * @brief Queries all the values from the driver
     * @return
     */
    bool                        queryValues(std::string workPath);

    std::string                 valueOverview();

    std::string                 name(){return this->_name;}
private:
    std::string                 _name;
    std::vector<WSValue>        _values;

    uint                        _nextLVId;

    HNPython*                   _pyInstance;
    PyModule                    _driverPyModule;
};

#endif // WSDRIVER_H
