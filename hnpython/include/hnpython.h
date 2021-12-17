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
	 * @brief   Executes a function of a module
	 * @param   modName                     The name of the module
	 * @param   funName                     The name of the function
	 * @param   args                        A Tuple of arguments
	 * @return  The return value in a special form:
	 *          "E1"                        An error
	 *              "ES1"                   System (1) - python not running
	 *              "ES2"                   System (2) - module not found
	 *              "ES3"                   System (3) - function not found
	 *          "I1"                        Integer (1)
	 *          "F2.1"                      Float (2.1)
	 *          "SHello"                    String (Hello)
	 *          "V"                         Void
	 */
	std::string                             execModFunction(std::string modName, std::string funName, void* args);

	/**
	 * @brief   Returns if the Python interpreter is running
	 **/
	bool                                    isRunning(){return this->_py_running;}

private:
	bool                                    _py_running;

	//Map of name and the module
	std::map<std::string, PyModule*>        _modules;
};

#endif // HNPYTHON_H
