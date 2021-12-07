include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PROJECT_SOURCE_DIR}/hnparser/include)

#HNConfig
include_directories(${PROJECT_SOURCE_DIR}/hnconfig/include)
#HNParser
include_directories(${PROJECT_SOURCE_DIR}/hnparser/include)
#HNDrivers
include_directories(${PROJECT_SOURCE_DIR}/hndrivers/include)
#HomeNetException
include_directories(${PROJECT_SOURCE_DIR}/homenet/include)

find_package(Qt5 COMPONENTS Core REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE HEADERS "include/**.h")
file(GLOB_RECURSE SOURCES "src/**.cpp")

add_library(hnhistory ${SOURCES} ${HEADERS})

target_link_libraries(hnhistory Qt5::Core stdc++fs hnconfig homenet)

add_dependencies(hnhistory hnparser)
