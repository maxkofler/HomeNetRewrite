#ifndef PYMODULE_H
#define PYMODULE_H

class PyModule;

#include "hnpython.h"
#include "pyargs.h"

#include <string>

class PyModule{
public:
	PyModule(HNPython* pyInstance);
	~PyModule();

	/**
	 * @brief	Imports the module from the specified module name
	 * @param	name			The name of the module: "mypackage.mymodule", you must not append .py!
	 */
	bool						import(std::string name);

	/**
	 * @brief	Removes all the modules data from memory
	 */
	void						remove();

	/**
	 * @brief	Executes a function of this module
	 * @param	funName			The name of the funciton to execute
	 * @param	args			The arguments of the function to execute
	 * @return	ES				System errore:
	 * 				ES1			Python instance not running
	 * 				ES2			Python module was not imported
	 * 				ES3			Python function not loaded (NULL returned)
	 * 				ES4			Python function is not callable
	 * 				ES5			Exception during call of function
	 * 				ES6			Function call failed (NULL returned)
	 * 			V				No return value
	* 			S[]				String value following: 		"SVALUE" 	-> 		"VALUE"
	 * 			I[]				Integer value following 		"I10" 		-> 		10
	 * 			F[]				Float value following			"F1.99" 	-> 		1.99f
	 * 			...
	 */
	std::string					exec(std::string funName, PyArgs* args);

	friend class HNPython;

#ifndef FRIEND_PYMODULE
private:
#endif

	/** @brief	The Python instance wrapper */
	HNPython*					_pyInst;

	/** @brief	Is true if the if the module is loaded */
	bool						_is_imported;

	/** @brief	The name of the module */
	std::string					_name;


	//
	//	Python pointers
	//

	//is_imported
	/** @brief	PyObject containing the module name for Python */
	void*						_pName;

	/** @brief	PyObject* containing the module */
	void*						_pModule;
};

#endif
