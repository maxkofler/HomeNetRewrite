include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PROJECT_SOURCE_DIR}/homenet/include)

#hnconfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#hndrivers
include_directories(${PROJECT_SOURCE_DIR}/hndrivers/include ${PROJECT_SOURCE_DIR}/hnpython/include)

#hndrivers
include_directories(${PROJECT_SOURCE_DIR}/hnhistory/include)

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

    src/hnnetworking/messageProcessing/processMessage.cpp
    src/hnnetworking/messageProcessing/processValueRequest.cpp
    src/hnnetworking/messageProcessing/processSystemRequest.cpp
    src/hnnetworking/messageProcessing/processHelpRequest.cpp
    )

add_library(hnnetworking ${SOURCES} ${HEADERS})

target_link_libraries(hnnetworking Qt5::Network hnconfig hndrivers)
