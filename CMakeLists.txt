cmake_minimum_required(VERSION 3.5)

project(HomeNet LANGUAGES CXX)

find_package(PythonLibs REQUIRED)

add_subdirectory(Log)
add_subdirectory(Argparser)

add_subdirectory(hnpython)
add_subdirectory(hnparser)
add_subdirectory(hnconfig)

include_directories(include Log/include Argparser/include ${PYTHON_INCLUDE_DIRS})

#HomeNet internal headers
include_directories(
    hnpython/include
    hnparser/include
    hnconfig/include
    )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(HomeNet
    main.cpp)

target_link_libraries(HomeNet Qt5::Core log argparser ${PYTHON_LIBRARIES})
target_link_libraries(HomeNet hnpython hnparser hnconfig)

add_dependencies(HomeNet log argparser)
add_dependencies(HomeNet hnpython hnparser hnconfig)
