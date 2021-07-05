include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

#hnconfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#hnpython
include_directories(${PROJECT_SOURCE_DIR}/hnpython/include)

set (HEADERS
    include/hndrivers.h
    include/hndriver.h
    )

set (SOURCES
    src/hndrivers/hndrivers.cpp
    src/hndrivers/init.cpp
    src/hndrivers/loadDrivers.cpp
    src/hndrivers/p_parseDriverlist.cpp
    src/hndrivers/p_importDrivers.cpp

    src/hndriver/hndriver.cpp
    src/hndriver/addValue.cpp
    )

add_library(hndrivers ${SOURCES} ${HEADERS})

target_link_libraries(hndrivers hnconfig hnparser hnpython)

add_dependencies(hndrivers hnconfig hnparser hnpython)
