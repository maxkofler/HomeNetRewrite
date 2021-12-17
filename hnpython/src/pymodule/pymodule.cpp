#include "log.h"
#include "pymodule.h"

PyModule::PyModule(HNPython* pyInst)
	:	_is_imported(false), _pyInst(pyInst)
{
	FUN();
}

PyModule::~PyModule(){
	FUN();

	this->remove();
}
