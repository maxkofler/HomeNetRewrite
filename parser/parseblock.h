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
    ~ParseBlock(){
        FUN();
        this->_blocks.clear();
    }

    /**
     * @brief Tries to parse the contents of this block from a line
     * @param line              The string containing the line to parse from
     * @return                  The ammount of blocks parsed
     */
    int                         parseFromLine(std::string line);

    std::string                 toString();

    std::vector<std::string>    getBlocks(){return this->_blocks;}

    std::string                 getBlockAt(uint pos){
        if (pos < this->_blocks.size())
            return this->_blocks.at(pos);
        return std::string("");
    }

    size_t                      getBlockCount(){return this->_blocks.size();}

    //setters
    void                        append(std::string e){this->_blocks.push_back(e);}
private:
    std::vector<std::string>    _blocks;
};

#endif // PARSEBLOCK_H
