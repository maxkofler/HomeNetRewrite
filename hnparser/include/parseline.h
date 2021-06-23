#ifndef __PARSELINE_H__
#define __PARSELINE_H__

class Parseline;

#include <string>
#include <vector>

#include "log.h"

class Parseline{
public:
    Parseline();
    ~Parseline();

    /**
     * @brief   Parses the contents of this line from a provided string
     *          The current block vector gets deleted
     * @param   line                        The line to parse from
     * @param   opener                      The opening char of a block (eg. '<')
     * @param   closer                      The closing char of a block (eg. '>')
     * @return                              The amount of blocks parsed
     */
    int                                     parseFromLine(std::string line, char opener, char closer);


    std::vector<std::string>                getBlocks(){return this->_blocks;}

private:
    std::vector<std::string>                _blocks;

};

#endif
