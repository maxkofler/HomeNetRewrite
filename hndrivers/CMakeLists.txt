include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

find_package(PythonLibs REQUIRED)

#hnconfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#hnpython
include_directories(${PROJECT_SOURCE_DIR}/hnpython/include ${PYTHON_INCLUDE_DIRS})

#hnhistory
include_directories(${PROJECT_SOURCE_DIR}/hnhistory/include)

set (HEADERS
    include/hndrivers.h
    include/hndriver.h
    )

set (SOURCES
    #HNDrivers
    #public
    src/hndrivers/hndrivers.cpp
    src/hndrivers/init.cpp
    src/hndrivers/loadDrivers.cpp
    src/hndrivers/sync.cpp
    #private
    src/hndrivers/p_parseDriverlist.cpp
    src/hndrivers/p_importDrivers.cpp

    #HNDriver
    #public
    src/hndriver/hndriver.cpp
    src/hndriver/addValue.cpp
    )

add_library(hndrivers ${SOURCES} ${HEADERS})

target_link_libraries(hndrivers hnconfig hnparser hnpython hnhistory ${PYTHON_LIBRARIES})

add_dependencies(hndrivers hnconfig hnparser hnpython hnhistory)
