include_directories(include ${PROJECT_SOURCE_DIR}/Log/include ${PROJECT_SOURCE_DIR}/hnparser/include)

set (HEADERS
    include/hnconfig.h
    include/configQueryException.h
    )

set (SOURCES
    src/hnconfig.cpp
    src/parse.cpp
    src/getConfig.cpp
    src/getFirstConfig.cpp
    )

add_library(hnconfig ${SOURCES} ${HEADERS})

target_link_libraries(hnconfig hnparser)

add_dependencies(hnconfig hnparser)
