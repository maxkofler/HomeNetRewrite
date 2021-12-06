#ifndef __HNHISTORYDAEMON_EXCEPTIONS_H__
#define __HNHISTORYDAEMON_EXCEPTIONS_H__

#include "homenet_exception.h"

class JobTypeMissmatchException : public HomeNetException{

public:
	JobTypeMissmatchException() : 
	HomeNetException("Job type missmatched", 
	"The provided job type did not match with the expected, arguments will do not work!"){

	}
};

#endif