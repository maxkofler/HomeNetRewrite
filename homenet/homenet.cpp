#include "homenet.h"

HomeNet::HomeNet(std::string configPath){
    this->_config = new HNConfig(configPath);
    this->_py = new HNPython();
    this->_py->addPythonPath(this->_config->getConfig("pythonpath"));
}

HomeNet::~HomeNet(){
    delete this->_config;
    delete this->_py;
    delete this->_ws;
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
