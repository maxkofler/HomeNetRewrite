include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

set (HEADERS
    include/hnparser.h
    )

set (SOURCES
    src/hnparser.cpp
    )

add_library(hnparser ${SOURCES} ${HEADERS})
