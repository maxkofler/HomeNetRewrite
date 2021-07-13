#include "hnhistory.h"

#include <filesystem>
#include <ctime>

bool HNHistory::append(hnvalue_t value){
    FUN();

    LOGF("Appending history of value \"" + value.drivername + "." + value.name + "\"");

    std::string vHistoryDir = this->_historyDir + "/" + value.drivername + "/";

    //Check if all directories for the value history exist
    if (!std::filesystem::exists(vHistoryDir)){
        std::filesystem::create_directories(vHistoryDir);
    }

    std::ofstream outFile;
    outFile.open(vHistoryDir + value.name + ".hnhist", std::ios::app);

    if (!outFile.is_open()){
        LOGE("Could not open file " + vHistoryDir + value.name + ".hnhist for appending");
        return false;
    }

    outFile << "<" << std::to_string(std::time(0)) << "><" << value.datatype << "><" << value.value << ">" << std::endl;

    outFile.close();

    return true;
}
