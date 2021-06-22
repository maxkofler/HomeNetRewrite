include_directories(include ../Log/include ${PYTHON_INCLUDE_DIRS})

find_package(PythonLibs REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)

set (HEADERS
    include/hnpython.h
    include/pymodule.h
    )

set (SOURCES
    src/hnpython/hnpython.cpp
    src/hnpython/startPython.cpp
    src/hnpython/stopPython.cpp
    src/hnpython/appendPath.cpp
    src/hnpython/loadModule.cpp
    src/hnpython/execModFunction.cpp

    src/pymodule/pymodule.cpp
    )

add_library(hnpython ${SOURCES} ${HEADERS})

target_link_libraries(hnpython ${PYTHON_LIBRARIES} Qt5::Core)
