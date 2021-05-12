#ifndef HNDRIVER_H
#define HNDRIVER_H

class HNDriver;

#include "log/log.h"
#include "homenet/hnvalue/hnvalue.h"
#include "homenet/hnpython/hnpython.h"
#include "parser/parseblock.h"

#include <vector>
#include <string>

class HNDriver{
public:
    HNDriver();
    ~HNDriver();

    bool                            fetchFromBlock(ParseBlock block);

    void                            addValue(HNValue v);

    void                            setPyModule(PyModule mod){FUN(); this->_pyModule = mod; this->_moduleLoaded=true;}

    bool                            syncValues(std::string workDir);

    std::string                     getName(){return this->_name;}
    std::string                     getOverview();

private:
    std::string                     _name;
    std::vector<HNValue>            _values;

    bool                            _moduleLoaded;
    PyModule                        _pyModule;

    //Private functions:
    bool                            p_resumeDriver();
    std::string                     p_callValue(HNValue& v, std::string workDir);
    bool                            p_pauseDriver();
};

#endif // HNDRIVER_H
