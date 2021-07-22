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
    ret += "<" + std::to_string(((HNDriver*)driver)->id()) + ">";
    ret += "<" + name + ">";
    ret += "<" + std::to_string(gID) + ">";
    ret += "<" + datatype + ">";
    ret += "<" + displaytype + ">";
    ret += "<" + value + ">";
    ret += "<" + unit + ">";

    return ret;
}
