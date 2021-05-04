#include "wsdriverlist.h"

#include <Python.h>

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

bool WSDriverList::importPythonDrivers(HNPython* pyInst){
    for (size_t i = 0; i < this->_drivers.size(); i++){
        std::string name = this->_drivers.at(i).name() + ".main";
        auto mod = pyInst->loadModule(name);
        if (mod.imported())
            this->_drivers.at(i).setPythonModule(mod, pyInst);
        else{
            LOGE("Not adding module with name \"" + name + "\"!");
        }
    }
    return true;
}

bool WSDriverList::callValues(std::string workDir){
    for (size_t i = 0; i < this->_drivers.size(); i++){
        WSDriver& curDriver = this->_drivers.at(i);
        curDriver.queryValues(workDir);
    }
    return true;
}
