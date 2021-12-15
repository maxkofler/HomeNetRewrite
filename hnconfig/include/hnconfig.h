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

	/**
	 * @brief   Fetches the first config of the specified key
	 * @param   key                         The key to search for
	 * @param   throwException              Whether to throw a configNotFoundException if the key was not found
	 * @return  The string of the first config found, empty if none found
	 */
	std::string                             getFirstConfig(std::string key, bool throwException = false);

#ifndef FRIEND_HNCONFIG
private:
#endif

    HNParser                                _parser;
};

#endif
