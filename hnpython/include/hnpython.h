#ifndef HNPYTHON_H
#define HNPYTHON_H

class HNPython;

#include <map>

#include "log.h"

#include "pymodule.h"
#include "pyargs.h"

class HNPython
{
public:
	HNPython();
	~HNPython();

	/**
	 * @brief   Starts the python-interpreter
	 * @param   force                       Restart python if already running
	*/
	void                                    startPython(bool force = false);

	/**
	 * @brief   Stops the python-interpreter (clears all modules)
	 */
	void                                    stopPython();

	/**
	 * @brief   Appends the Python PATH variable
	 * @param   path                        Path to append
	 */
	bool                                    appendPath(std::string path);

	/**
	 * @brief   Loads (imports) a module within the python-path
	 * @param   name                        The name of the module
	 */
	bool                                    loadModule(std::string name);

	/**
	 * @brief	Returns a pointer to the asked module
	 * @param	name						The name of the module
	 * @return	nullptr if the module does not exist
	 */
	PyModule*								getModule(std::string name);

	/**
	 * @brief   Returns if the Python interpreter is running
	 **/
	bool                                    isRunning(){return this->_py_running;}

private:
	bool                                    _py_running;

	//Map of name and the module
	std::map<std::string, PyModule*>        _modules;
};

#endif
