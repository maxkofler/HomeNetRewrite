#include "hnhistory.h"

bool HNHistory::init(HNConfig &config){
    FUN();

    this->_historyDir = config.getConfig("historydir", true).back();

    return true;
}
