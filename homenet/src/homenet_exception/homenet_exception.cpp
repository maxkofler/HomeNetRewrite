#include "homenet_exception.h"
#include "log.h"

HomeNetException::HomeNetException(std::string what){
	FUN();

	LOGDE("[HomeNetException] Exception \"" + what + "\" trapped!");

	this->_what = what;
	this->_precise = "[unknown]";
}

HomeNetException::HomeNetException(std::string what, std::string precise){
	FUN();

	LOGDE("[HomeNetException] Exception \"" + what + "\" -> \"" + precise + "\" trapped!");

	this->_what = what;
	this->_precise = precise;
}