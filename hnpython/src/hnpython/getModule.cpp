#include "hnpython.h"

PyModule* HNPython::getModule(std::string name){
	FUN();

	if (this->_modules.count(name) <= 0)
		return nullptr;

	return this->_modules.at(name);
}
