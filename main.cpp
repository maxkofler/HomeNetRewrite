#include <iostream>

#include "log.h"

#include "hnpython.h"

Log* hlog;

int main()
{
    hlog = new Log(Log::D, false);

    HNPython py;
    py.startPython(true);
    py.appendPath("./");
    py.loadModule("main");

    PyObject* args;
    args = PyTuple_New(0);
    //PyTuple_SetItem(args, 0, 0);
    py.execModFunction("main", "start", args);

    FUN();
    LOGD("Hello");
    return 0;
}
