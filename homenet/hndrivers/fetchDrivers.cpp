#include "hndrivers.h"

void HNDrivers::p_fetchDrivers(){
    FUN();
    bool inDriver = false;
    HNDriver* curDriver = nullptr;
    uint nextlId = 0;

    for (auto& i : this->_driverListParser->getVector()){

        if (i.getBlockAt(0) == "driver"){
            LOGD("Opening new driver");
            inDriver = true;
            curDriver = new HNDriver();
            if (!curDriver->fetchFromBlock(i)){
                LOGE("Error on fetching driver data!");
                inDriver = false;
                delete curDriver;
            }
            nextlId = 0;
        }

        else if (i.getBlockAt(0) == "/driver"){
            if (inDriver && curDriver != nullptr){
                LOGD("End of driver!");
                inDriver = false;
                this->_drivers.push_back(*curDriver);
                delete curDriver;
                curDriver = nullptr;
            }else{
                LOGE("/driver fetched without being in a driver!");
            }
        }

        else if (i.getBlockAt(0) == "value"){
            if (!inDriver && curDriver != nullptr){
                LOGE("Fetched a value entry without being in a driver, ignoring!")
            }else{
                LOGD("Fetching a value...");
                //Create a new value
                HNValue val;
                //Fetch its data
                val.fromParsedBlock(i, this->_nextId, nextlId);
                //Push it and increment counters
                curDriver->addValue(val);
                this->_nextId++;
                nextlId++;
            }
        }
    }
}
