include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

set (HEADERS
    include/hnparser.h
    include/parseline.h
    )

set (SOURCES
    src/hnparser/hnparser.cpp
    src/hnparser/parseStream.cpp

    src/parseline/parseline.cpp
    src/parseline/parseFromLine.cpp
    )

add_library(hnparser ${SOURCES} ${HEADERS})
