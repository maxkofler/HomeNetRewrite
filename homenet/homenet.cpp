#include "homenet.h"

HomeNet::HomeNet(std::string configPath){
    this->_config = new HNConfig(configPath);
}

bool HomeNet::startWS(){
    std::string wsconfigPath = _config->getConfig("wsconfig");
    if (!wsconfigPath.empty()){
        this->_ws = new Weathersens(wsconfigPath, this);
        return true;
    }else{
        return false;
    }
}
