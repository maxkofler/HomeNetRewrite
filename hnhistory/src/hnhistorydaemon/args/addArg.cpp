#include "hnhistorydaemon/args.h"
#include "log.h"

void Args::addArg(void* arg){
	FUN();

	this->_args.push_back(arg);
}