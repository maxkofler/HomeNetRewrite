#ifndef WSCONFIG_H
#define WSCONFIG_H

class WSConfig;

#include "log/log.h"
#include "parser/parser.h"

#include <string>

class WSConfig
{
public:
    WSConfig(std::string configPath);

    /**
     * @brief Returns the config provided under the name
     * @param name          The name the config has
     * @return              The config, empty string when not found
     */
    std::string             getConfig(std::string name);
private:
    Parser                  _parser;
};

#endif // WSCONFIG_H
