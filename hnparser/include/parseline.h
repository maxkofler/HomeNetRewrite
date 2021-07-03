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
    int                                     parseFromLine(std::string line, char opener, char closer, bool acceptEmpty = false);

    /**
     * @brief   Converts this object to a line to write to something that can be parsed later
     * @param   opener                      The opening char of a block (eg. '<')
     * @param   closer                      The closing char of a block (eg. '>')
     * @return                              The string containing the string to write to the stream
     */
    std::string                             toParseLine(char opener, char closer);

    size_t                                  size(){return this->_blocks.size();}

    std::vector<std::string>                getBlocks(){return this->_blocks;}

    std::string                             getBlock(size_t pos){return this->_blocks.at(pos);}

private:
    std::vector<std::string>                _blocks;

};

#endif
