#ifndef __HNCONFIG_H__
#define __HNCONFIG_H__

class HNConfig;

#include "log.h"

#include <string>
#include <vector>

#include "hnparser.h"

class HNConfig{
public:
    HNConfig();

    /**
     * @brief   Parses the HomeNet configuration file
     * @param   path                        The path to fetch the config from
     */
    bool                                    parse(std::string path);

    /**
     * @brief   Fetches the config under the specified key
     * @param   key                         The key to search for
     * @param   throwException              Whether to throw a configNotFoundException if the key was not found
     * @return  A vector containing all the strings under the key
     */
    std::vector<std::string>                getConfig(std::string key, bool throwException = false);

private:
    HNParser                                _parser;
};

#endif
