#include "hndrivers.h"

bool HNDrivers::p_parseDriverlist(){
    FUN();
    std::string fStr = "Parsing driverlist: ";

    //Assume everything is ok, this function gets only called from loadDrivers where
    //all the checks were already made

    auto lines = this->_driverlistParser.getLines();

    LOGD(fStr + "Parsing " + std::to_string(lines.size()) + " lines...");

    size_t driversParsed = 0;
    size_t valuesParsed = 0;


    bool driver_open = false;    //If currently a driver is parsing or if no driver tag is opened
    HNDriver* curDriver;
    for (auto line : lines){

        //Check if the line is long enough
        if (line.size() <= 0){
            LOGW(fStr + "Parser warning: Line is empty (bug?)!");
            continue;
        }

        if (line.getBlock(0) == "driver"){
            if (driver_open == true){
                LOGE(fStr + "Parser error: Started a new driver when one was already open!");
                return false;
            }

            if (line.size() != 2){
                LOGE(fStr + "Invalid length of driver header (missing name?)!");
                return false;
            }

            curDriver = new HNDriver(line.getBlock(1));
            driver_open = true;
        }

        else if (line.getBlock(0) == "/driver"){
            if (driver_open == false){
                LOGE(fStr + "Parser error: Ended a driver without having one started!");
                return false;
            }

            if (curDriver->getValues().size() <= 0){
                LOGW(fStr + "Not adding driver \"" + curDriver->name() + "\": Has no members!");
                curDriver = nullptr;
                driver_open = false;
                continue;
            }

            {   //Give all values their ID
                size_t firstID = this->_nextVId;
                size_t curVID = 0;
                for (hnvalue_t* curValue : curDriver->getValues()){
                    curValue->gID = this->_nextVId;
                    curValue->lID = curVID;

                    this->_nextVId = this->_nextVId+1;
                    curVID++;
                }

                LOGI(   fStr + "Driver \"" + curDriver->name() + "\" has values from id #" + std::to_string(firstID) +
                        " - #" + std::to_string(this->_nextVId-1));
            }

            driversParsed++;
            this->_drivers.push_back(curDriver);
            curDriver = nullptr;
            driver_open = false;
        }

        else if (line.getBlock(0) == "value"){
            if (!driver_open){
                LOGE(fStr + "Parser error: Defined value outside of a driver!");
                return false;
            }

            if (line.size() != 4){
                LOGW(fStr + "Parser error: Value line \"" + line.toParseLine('<', '>') + "\" has wrong length for parsing, ignoring!");
                continue;
            }

            //<value><value_name><value_display_type><value_unit>

            hnvalue_t* newValue = new hnvalue_t;

            newValue->name = line.getBlock(1);
            newValue->displaytype = line.getBlock(2);
            newValue->unit = line.getBlock(3);

            curDriver->addValue(newValue);

            valuesParsed++;
        }
    }

    LOGI(fStr + "Parsed " + std::to_string(driversParsed) + " drivers!");
    LOGI(fStr + "Parsed " + std::to_string(valuesParsed) + " values!");

    return true;
}
