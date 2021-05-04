#include "wsdriverlist.h"

WSDriverList::WSDriverList(std::string name){
    this->_listParser.parseFile(name);
    this->_nextGVId = 0;

    {//Copy drivers data into the vector
        auto vectLines = this->_listParser.getVector();

        size_t pos_vect = 0;
        while(pos_vect < vectLines.size()){
            if (vectLines.at(pos_vect).getBlockAt(0) == "driver"){
                WSDriver driver;
                if (driver.fetch(vectLines, &pos_vect, &_nextGVId)){
                    this->_drivers.push_back(driver);
                }
            }
            pos_vect++;
        }
    }
}
