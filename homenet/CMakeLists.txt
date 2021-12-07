include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PROJECT_SOURCE_DIR}/homenet/include)

#hnconfig
#include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#hndrivers
#include_directories(${PROJECT_SOURCE_DIR}/hndrivers/include ${PROJECT_SOURCE_DIR}/hnpython/include)

#hndrivers
#include_directories(${PROJECT_SOURCE_DIR}/hnhistory/include)

include_directories(
    ${PROJECT_SOURCE_DIR}/hndrivers/include
    ${PROJECT_SOURCE_DIR}/hnconfig/include
	${PROJECT_SOURCE_DIR}/hnparser/include
	${PROJECT_SOURCE_DIR}/hnpython/include
	${PROJECT_SOURCE_DIR}/hnhistory/include
	${PROJECT_SOURCE_DIR}/hnnetworking/include
)

find_package(Qt5 COMPONENTS Network REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file (GLOB_RECURSE SOURCES "src/**.cpp")
file (GLOB_RECURSE HEADERS "include/**.h")

add_library(homenet ${SOURCES} ${HEADERS})

target_link_libraries(homenet Qt5::Network hnconfig hndrivers)
