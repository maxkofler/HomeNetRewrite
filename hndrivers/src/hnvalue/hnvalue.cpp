#include "hnvalue.h"

#include "hndriver.h"

std::string hnvalue_t::toTransmissionString(){
    FUN();
    std::string ret = "";

    //Old message layout
    //<driverName><driverID><valueName><valueUnit><displayType><valueID><value><dataType>

    //New message layout
    //<driverName><driverID><valueName><valueID><dataType><displayType><value><valueUnit>


    ret += "<" + ((HNDriver*)driver)->name() + ">";
    ret += "<0>";
    ret += "<" + name + ">";
    ret += "<0>";
    ret += "<" + datatype + ">";
    ret += "<" + displaytype + ">";
    ret += "<" + value + ">";
    ret += "<" + unit + ">";

    return ret;
}
