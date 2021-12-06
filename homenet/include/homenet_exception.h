#ifndef __HOMENET_EXCEPTION_H__
#define __HOMENET_EXCEPTION_H__

#include <string>

class HomeNetException{

public:
	HomeNetException(std::string what);
	HomeNetException(std::string what, std::string precise);

	std::string						what(){return _what;}
	std::string						precise(){return _precise;}

protected:
	std::string						_what;
	std::string						_precise;
};

#endif