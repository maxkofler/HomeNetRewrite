#ifndef __HNDRIVER_H__
#define __HNDRIVER_H__

class HNDriver;

#include "log.h"

#include <string>
#include <vector>

typedef struct{
    std::string     drivername;
    std::string     name;
    std::string     displaytype;
    std::string     unit;
    std::string     datatype;
    std::string     value;
    size_t          lID;
    size_t          gID;
} hnvalue_t;

class HNDriver{
public:
    HNDriver(std::string name);
    ~HNDriver();

    /**
     * @brief   Adds a hnvalue_t to the driver
     * @param   newValue                    The new value to add (gets copied)
     */
    bool                                    addValue(hnvalue_t newValue);

    std::vector<hnvalue_t>                  getValues(){return this->_values;}
    std::string                             name(){return this->_name;}

private:
    std::vector<hnvalue_t>                  _values;

    std::string                             _name;
};

#endif
