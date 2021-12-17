#ifndef PYMODULE_H
#define PYMODULE_H

class PyModule;

#include <string>

#include "log.h"

#include "hnpython.h"

class PyModule
{
public:
    PyModule(HNPython* pyInstance);
    ~PyModule();

	/**
	 * @brief	Imports the module from the specified module name
	 * @param	name						The name of the module: "mypackage.mymodule", you must not append .py!
	 */
	bool									import(std::string name);

    friend class HNPython;
private:
	HNPython*								_pyInst;
    bool                                    _is_imported;
    std::string                             _name;
    void*                                   _pName;

    void*                                   _pModule;
    void*                                   _pDict;

    /*
    PyObject*                               _pName;         //The name in pystring form
    PyObject*                               _pModule;       //The module itself
    PyObject*                               _pDict;         //Its dictionary for symbols
    */
};

#endif // PYMODULE_H
