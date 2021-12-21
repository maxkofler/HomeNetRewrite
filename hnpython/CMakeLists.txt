include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PYTHON_INCLUDE_DIRS})

find_package(PythonLibs REQUIRED)

file (GLOB_RECURSE HEADERS "./**.h")
file (GLOB_RECURSE SOURCES "./**.cpp")

add_library(hnpython ${SOURCES} ${HEADERS})

target_link_libraries(hnpython ${PYTHON_LIBRARIES})
