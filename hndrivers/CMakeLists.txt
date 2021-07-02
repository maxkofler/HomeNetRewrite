include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

#hnconfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#hnpython
include_directories(${PROJECT_SOURCE_DIR}/hnpython/include ${PYTHON_INCLUDE_DIRS})

set (HEADERS
    include/hndrivers.h
    )

set (SOURCES
    src/hndrivers.cpp
    src/init.cpp
    src/loadDrivers.cpp
    src/p_parseDriverlist.cpp
    )

add_library(hndrivers ${SOURCES} ${HEADERS})

target_link_libraries(hndrivers hnconfig hnparser hnpython ${PYTHON_LIBRARIES})

add_dependencies(hndrivers hnconfig hnparser hnpython)
