#ifndef HNPYTHON_H
#define HNPYTHON_H

class HNPython;

#include "log/log.h"
#include "pymodule/pymodule.h"

#include <string>
#include <Python.h>

//To convert to wstring
#include <QString>

class HNPython
{
public:
    HNPython();
    ~HNPython();

    /**
     * @brief Reloads the Python-interpreter
     */
    void                        restartPython();

    /**
     * @brief Adds a specified path to the Python-PATH
     * @param path              The path to add
     */
    void                        addPythonPath(std::string path);

    /**
     * @brief Loads the module specified from Python-PATH
     * @param name              The name of the module to load
     * @return                  Success
     */
    PyModule                    loadModule(std::string name);

    std::string                 execFunction(std::string name, PyObject* args);
};

#endif // HNPYTHON_H
