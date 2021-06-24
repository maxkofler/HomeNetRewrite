#include "hnconfig.h"

#include <fstream>

bool HNConfig::parse(std::string path){
    FUN();

    std::ifstream inFile;
    inFile.open(path);

    if (!inFile.is_open()){
        LOGE("Could not find HomeNet config file \"" + path + "\"!");
        inFile.close();
        return false;
    }

    if (this->_parser.parseStream(inFile) <= 0){
        LOGE("HomeNet config file \"" + path + "\" is empty!");
        inFile.close();
        return false;
    }

    inFile.close();

    return true;
}
