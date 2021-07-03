#ifndef __HNPARSER_H__
#define __HNPARSER_H__

class HNParser;

#include <istream>
#include <ostream>

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
    int                                     parseStream(std::istream& instream, bool acceptEmpty = false);

    /**
     * @brief   Clears all lines from cache
     */
    void                                    clear();

    /**
     * @brief   Getter for all the lines
     * @return                              The vector of lines
     */
    std::vector<Parseline>                  getLines(){return this->_lines;}

    /**
     * @brief   Appends the provided line to the list of lines
     * @param   line                        The line to append to the parsed cache
     */
    void                                    append(Parseline line);

    /**
     * @brief   Writes all the contents of the parsed cache to the provided stream
     * @param   outstream                   The stream to write to
     * @return                              The amount of lines written
     */
    int                                     writeToStream(std::ostream& outstream);

    size_t                                  size(){return this->_lines.size();}

private:
    std::vector<Parseline>                  _lines;
};

#endif
