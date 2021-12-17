#ifndef __PYARGS_H__
#define __PYARGS_H__

#include <cstddef>

/**
 * @brief A class that wraps a python argument tuple
 *
 */
class PyArgs{

public:
	PyArgs(size_t argc);

	void                setItem(size_t pos, const char* type, int value);
	void                setItem(size_t pos, const char* type, const char* value, int len);

	void*               getArgv(){return this->_argv;}


private:
	size_t              _argc;
	void*               _argv;

};

#endif
