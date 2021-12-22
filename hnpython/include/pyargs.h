#ifndef __PYARGS_H__
#define __PYARGS_H__

#include <cstddef>
#include <string>

/**
 * @brief A class that wraps a python argument tuple
 *
 */
class PyArgs{

public:
	PyArgs(int argc);
	~PyArgs();

	bool                setLongItem(int pos, long value);
	bool                setStringItem(int pos, std::string value);

	/**
	 * @brief	Returns the PyTuple as a PyObject* cast to void*
	 */
	void*               getArgv(){return this->_argv;}


private:
	size_t              _argc;
	void*               _argv;

};

#endif
