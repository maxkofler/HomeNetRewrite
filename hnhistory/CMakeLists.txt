include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#HNConfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include)
#HNParser
include_directories(${PROJECT_SOURCE_DIR}/hnparser/include)
#HNPDrivers
include_directories(${PROJECT_SOURCE_DIR}/hndrivers/include)

set (HEADERS
    include/hnhistory.h
    )

set (SOURCES
    src/hnhistory/hnhistory.cpp
    src/hnhistory/init.cpp
    src/hnhistory/open.cpp
    )

add_library(hnhistory ${SOURCES} ${HEADERS})

target_link_libraries(hnhistory hnparser)

add_dependencies(hnhistory hnparser)
