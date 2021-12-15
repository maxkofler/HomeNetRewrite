include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PYTHON_INCLUDE_DIRS})

find_package(PythonLibs REQUIRED)

set (HEADERS
    include/hnpython.h
    include/pymodule.h
    include/pyargs.h
    )

set (SOURCES
    src/hnpython/hnpython.cpp
    src/hnpython/startPython.cpp
    src/hnpython/stopPython.cpp
    src/hnpython/appendPath.cpp
    src/hnpython/loadModule.cpp
    src/hnpython/execModFunction.cpp

    src/pymodule/pymodule.cpp

    src/pyargs/pyargs.cpp
    src/pyargs/setitem.cpp
    )

add_library(hnpython ${SOURCES} ${HEADERS})

target_link_libraries(hnpython ${PYTHON_LIBRARIES})
