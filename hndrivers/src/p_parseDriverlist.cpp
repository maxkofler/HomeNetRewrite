#include "hndrivers.h"

bool HNDrivers::p_parseDriverlist(){
    FUN();

    //Assume everything is ok, this function gets only called from loadDrivers where
    //all the checks were already made

    auto lines = this->_driverlistParser.getLines();

    for (auto& line : lines){
        
    }
}