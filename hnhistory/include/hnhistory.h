#ifndef __HNHISTORY_H__
#define __HNHISTORY_H__

class HNHistory;

#include <fstream>
#include <string>

#include "log.h"

#include "hnparser.h"
#include "hndriver.h"
#include "hnconfig.h"

class HNHistory{

public:
    HNHistory();
    ~HNHistory();

    bool                                    init(HNConfig& config);

    bool                                    read(hnvalue_t value);

private:
    std::string                             _historyDir;

    HNParser                                _parser;
    std::fstream                            _historyFile;

};

#endif
