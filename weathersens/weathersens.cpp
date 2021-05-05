#include "weathersens.h"

Weathersens::Weathersens(std::string wsConfigPath, HomeNet* hn){
    FUN();
    this->_runlevel = -1;
    this->_hn = hn;
    this->_config = new WSConfig(wsConfigPath);
    std::string conf;

    //Fetch <driverdir> variable
    conf = this->_config->getConfig("driverdir");
    if (conf.empty()){
        LOGE("Could not find config for \"driverdir\", Weathersens will not load!");
        return;
    }
    this->_driverDir = conf;
    this->_hn->_py->addPythonPath(this->_driverDir);

    //Fetch <driverlist> variable
    conf = this->_config->getConfig("driverlist");
    if (conf.empty()){
        LOGE("Could not find config for \"driverlist\", Weathersens will not load!");
        return;
    }
    this->_driverListPath = conf;

    //Fetch <synctime> variable
    conf = this->_config->getConfig("synctime");
    if (conf.empty()){
        LOGE("Could not find config for \"driverlist\", Weathersens will not load!");
        return;
    }
    this->_syncTimeout = std::stoi(conf);

    this->_runlevel = 1;
    LOGD("Weathersens reached runlevel 1!");
    this->_driverlist = new WSDriverList(this->_driverListPath);
    this->_runlevel = 2;
    LOGD("Weathersens reached runlevel 2!");
    this->_driverlist->importPythonDrivers(this->_hn->_py);
    this->_runlevel = 3;
    LOGD("Weathersens reached runlevel 3!");
}

void Weathersens::callValues(){
    FUN();
    this->_m_driverlist.lock();
    std::string workDir = this->_hn->_config->getConfig("workdir");
    if (workDir.empty()){
        LOGE("Could not find workdir config!");
        return;
        this->_m_driverlist.unlock();
    }

    this->_driverlist->callValues(workDir);
    this->_m_driverlist.unlock();
}


Weathersens::~Weathersens(){
    delete this->_config;
    delete this->_driverlist;
}
