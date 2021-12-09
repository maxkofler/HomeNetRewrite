#ifndef __HNVALUE_H__
#define __HNVALUE_H__

#include "log.h"

#include <string>

struct hnvalue_s{
	void*           driver;
	std::string     name;
	std::string     displaytype;
	std::string     unit;
	std::string     datatype;
	std::string     value;
	size_t          lID;
	size_t          gID;

	unsigned long	syncTime;

	std::string     toTransmissionString();
};

typedef hnvalue_s hnvalue_t ;

#endif // HNVALUE_H
