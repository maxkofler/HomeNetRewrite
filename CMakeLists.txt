cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(HomeNet LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

enable_testing()

add_subdirectory(Log/googletest)
add_subdirectory(Log)

add_subdirectory(tests)

add_subdirectory(hnpython)
add_subdirectory(hnparser)
add_subdirectory(hnconfig)
add_subdirectory(hndrivers)
add_subdirectory(hnnetworking)
add_subdirectory(hnhistory)
add_subdirectory(homenet)

include_directories(include Log/include Log/googletest/googletest/include)

#HomeNet internal headers
include_directories(
    hnpython/include
    hnparser/include
    hnconfig/include
    hndrivers/include
    hnnetworking/include
    hnhistory/include
    homenet/include
)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file (GLOB_RECURSE SOURCES "main/src/**.cpp")

add_executable(HomeNet ${SOURCES})


target_link_libraries(HomeNet Qt5::Core stdc++fs log)
target_link_libraries(HomeNet hnconfig hndrivers hnhistory hnnetworking hnparser hnpython homenet)

add_dependencies(HomeNet log)
add_dependencies(HomeNet hnconfig hndrivers hnhistory hnnetworking hnparser hnpython homenet)
