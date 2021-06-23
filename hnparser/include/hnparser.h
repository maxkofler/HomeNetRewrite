#ifndef __HNPARSER_H__
#define __HNPARSER_H__

class HNParser;

#include <istream>

#include "log.h"

#include "parseline.h"

class HNParser{

public:
    HNParser();
    ~HNParser();

    /**
     * @brief   Parses the provided stream
     * @param   instream                    The stream to parse
     * @return  The amount of lines parsed
     */
    int                                     parseStream(std::istream& instream);

private:
    std::vector<Parseline*>                 _lines;
};

#endif
