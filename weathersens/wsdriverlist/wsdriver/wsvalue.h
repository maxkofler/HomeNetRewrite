#ifndef WSVALUE_H
#define WSVALUE_H

class WSValue;

#include "log/log.h"
#include "parser/parseblock.h"

#include <string>

class WSValue
{
public:
    WSValue();
    /*
    ~WSValue(){
        FUN();
    }
    */

    /**
     * @brief Fetches values from a parsed block
     * @param block             The block to  fetch from
     * @param lid               The ID of this value inside the driver
     * @param gId               The ID of this value inside Weathersens
     * @return
     */
    bool                        fromParsedBlock(ParseBlock block, uint lId, uint gId);

    std::string                 name(){return this->_name;}
    uint                        gId(){return this->_gId;}
    uint                        lId(){return this->_lId;}

    void                        value(char type, std::string value)  {
                                                                                this->_vtype = type;
                                                                                this->_value = value;
                                                                                this->_holdsValue = true;
                                                                            }

    std::string                 toString();
    std::string                 toTransmissionString();

private:
    bool                            _loaded;    //Whether this value was loaded correctly
    bool                            _holdsValue;//Whether this value is containing values for WS to get
    std::string                     _name;      //The Name / Description of the value
    std::string                     _dtype;     //The type of the value, affects how the value may be presented to the end user
    std::string                     _unit;      //The unit of the value, displayed to the user

    std::string                     _value;     //The effective value
    char                            _vtype;     //The type of value: N = nAV, I = int, S = string, F = float...

    uint                            _lId;       //The local ID inside the driver
    uint                            _gId;       //The global ID inside Weathersens
};

#endif // WSVALUE_H
