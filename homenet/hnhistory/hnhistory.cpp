#include "hnhistory.h"

HNHistory::HNHistory(std::string historyDir){
    this->_historyDir = historyDir;
    this->_historyParser = new Parser();
}

HNHistory::~HNHistory(){
    delete this->_historyParser;
}
