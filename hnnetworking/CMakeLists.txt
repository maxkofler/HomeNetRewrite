include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

#hnconfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include ${PROJECT_SOURCE_DIR}/hnparser/include)

find_package(Qt5 COMPONENTS Network REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (HEADERS
    include/hnnetworking.h
    )

set (SOURCES
    src/hnnetworking/hnnetworking.cpp
    src/hnnetworking/sl_onNewConnection.cpp
    src/hnnetworking/sl_onReadyRead.cpp
    src/hnnetworking/sl_onSocketStateChanged.cpp
    src/hnnetworking/start.cpp
    )

add_library(hnnetworking ${SOURCES} ${HEADERS})

target_link_libraries(hnnetworking Qt5::Network hnconfig)
