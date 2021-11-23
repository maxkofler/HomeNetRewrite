include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#HNConfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include)
#HNParser
include_directories(${PROJECT_SOURCE_DIR}/hnparser/include)
#HNPDrivers
include_directories(${PROJECT_SOURCE_DIR}/hndrivers/include)

find_package(Qt5 COMPONENTS Core REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (HEADERS
    include/hnhistory.h

    include/hnhistorydaemon.h
    )

set (SOURCES
    src/hnhistory/hnhistory.cpp
    src/hnhistory/init.cpp
    src/hnhistory/read.cpp
    src/hnhistory/append.cpp
    src/hnhistory/getHistory.cpp

    src/hnhistorydaemon/hnhistorydaemon.cpp
    )

add_library(hnhistory ${SOURCES} ${HEADERS})

target_link_libraries(hnhistory Qt5::Core stdc++fs hnparser)

add_dependencies(hnhistory hnparser)
