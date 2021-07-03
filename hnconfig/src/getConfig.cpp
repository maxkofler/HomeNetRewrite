#include "hnconfig.h"

#include "configQueryException.h"

std::vector<std::string> HNConfig::getConfig(std::string key, bool throwException){
    FUN();
    std::vector<std::string> ret;


    Parseline configLine;

    {
        auto configs = this->_parser.getLines();
        //Search for the config
        bool configFound = false;
        size_t i = 0;
        while (!configFound){
            if (i < configs.size()){
                if (configs[i].getBlock(0) == key){
                    configFound = true;
                    configLine = configs[i];
                    continue;
                }
                i++;
            }
            else
                break;
        }

        if (!configFound){
            if (throwException){
                ConfigQueryException e;
                e.what = "Could not find config with key \"" + key + "\"!";
                throw e;
            }else{
                LOGW("Could not find config with key \"" + key + "\"!");
                return ret;
            }
        }
    }

    auto configBlocks = configLine.getBlocks();

    if (configBlocks.size() < 2){
        if (throwException){
            ConfigQueryException e;
            e.what = "Config with key \"" + key + "\" was found but contains no data!";
            throw e;
        }else{
            LOGW("Config with key \"" + key + "\" was found but contains no data!")
                    return ret;
        }
    }

    std::string dbugString = "Found config -> Key: \"" + key + "\": ";

    for(size_t i = 1; i < configBlocks.size(); i++){
        ret.push_back(configBlocks[i]);
        dbugString += "\"" + configBlocks[i] + "\"";
    }

    LOGD(dbugString);

    return ret;
}
