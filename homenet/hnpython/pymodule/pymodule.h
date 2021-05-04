#ifndef PYMODULE_H
#define PYMODULE_H

class PyModule;

#include "log/log.h"
#include "homenet/hnpython/hnpython.h"

#include <Python.h>
#include <string>

class PyModule
{
public:
    PyModule();
    ~PyModule();

    /**
     * @brief Executes the specified function in this module
     * @param name              The name of the function
     * @param args              A PyObject* Tuple containing the args, NULL when no args
     * @return                  The return of the function, empty on error
     */
    std::string                 execFunction(std::string name, PyObject* args);

    bool                        imported(){return this->_is_loaded;}

    friend class HNPython;
private:
    PyObject                    *_pName;
    PyObject                    *_pModule;
    PyObject                    *_pDict;

    bool                        _is_loaded;
};

#endif // PYMODULE_H
