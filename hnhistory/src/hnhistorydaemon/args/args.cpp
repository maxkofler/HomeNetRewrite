#include "hnhistorydaemon/args.h"
#include "log.h"

Args::Args(){
	FUN();
}

Args::Args(std::vector<std::string> args){
	FUN();

	this->_args = args;
}
