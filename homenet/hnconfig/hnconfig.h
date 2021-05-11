#ifndef HNCONFIG_H
#define HNCONFIG_H

/**
 *Required configs:
 *
 *      -
 */

class HNConfig;

#include "log/log.h"
#include "parser/parser.h"

#include <string>

class HNConfig
{
public:
    HNConfig(std::string fPath);

    /**
     * @brief Returns the config provided under the name
     * @param name          The name the config has
     * @return              The config, empty string when not found
     */
    std::string             getConfig(std::string name);

private:
    Parser                  _parser;
};

#endif // HNCONFIG_H
