#include "hndrivers.h"

bool HNDrivers::p_importDrivers(){
    FUN();
    std::string fStr = "Importing drivers: ";

    //Assume everything is ok, this function gets only called from loadDrivers where
    //all the checks were already made

    LOGI(fStr + "Appending Python-PATH");
    this->_pyInst->appendPath(this->_driversPath);

    size_t driversImported = 0;

    for (HNDriver* curDriver : this->_drivers){

        LOGI(fStr + "Importing driver \"" + curDriver->name() + "\"");

        if (!this->_pyInst->loadModule(curDriver->name() + ".main")){
            LOGW("Failed to import driver \"" + curDriver->name() + "\"!");
            continue;
        }

        driversImported++;
    }

    LOGI(fStr + "Imported " + std::to_string(driversImported) + " drivers");

    return true;
}
