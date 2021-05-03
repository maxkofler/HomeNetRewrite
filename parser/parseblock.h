#ifndef PARSEBLOCK_H
#define PARSEBLOCK_H

class ParseBlock;

#include <string>
#include <vector>

#include "log/log.h"
#include "parser.h"

class ParseBlock
{
public:
    ParseBlock();

    /**
     * @brief Tries to parse the contents of this block from a line
     * @param line              The string containing the line to parse from
     * @return                  The ammount of blocks parsed
     */
    int                         parseFromLine(std::string line);

    std::string                 toString();

    std::vector<std::string>    getBlocks(){return this->_blocks;}

    size_t                      getBlockCount(){return this->_blocks.size();}
private:
    std::vector<std::string>    _blocks;
};

#endif // PARSEBLOCK_H
