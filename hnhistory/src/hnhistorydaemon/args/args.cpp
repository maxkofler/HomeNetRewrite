#include "hnhistorydaemon/args.h"
#include "log.h"

Args::Args(){
	FUN();
}

Args::Args(std::vector<void*> args){
	FUN();

	this->_args = args;
}
