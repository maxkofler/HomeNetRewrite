cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(HomeNet LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

add_subdirectory(Log/googletest)
add_subdirectory(Log)
add_subdirectory(Argparser)

add_subdirectory(hnpython)
add_subdirectory(hnparser)
add_subdirectory(hnconfig)
add_subdirectory(hndrivers)
add_subdirectory(hnnetworking)
add_subdirectory(hnhistory)

include_directories(include Log/include Argparser/include)

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

file (GLOB_RECURSE SOURCES "homenet/src/**.cpp")
file (GLOB_RECURSE HEADERS "homenet/include/**.h")

add_executable(HomeNet
    main.cpp

    ${HEADERS}
    ${SOURCES}
    )


target_link_libraries(HomeNet Qt5::Core stdc++fs log argparser)
target_link_libraries(HomeNet hnpython hnparser hnconfig hndrivers hnnetworking hnhistory)

add_dependencies(HomeNet log argparser)
add_dependencies(HomeNet hnpython hnparser hnconfig hndrivers hnnetworking hnhistory)
