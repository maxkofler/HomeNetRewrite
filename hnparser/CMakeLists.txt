include_directories(include ${PROJECT_SOURCE_DIR}/Log/include)

set (HEADERS
    include/hnparser.h
    include/parseline.h
    )

set (SOURCES
    src/hnparser/hnparser.cpp
    src/hnparser/parseStream.cpp
    src/hnparser/clear.cpp
    src/hnparser/append.cpp
    src/hnparser/writeToStream.cpp

    src/parseline/parseline.cpp
    src/parseline/parseFromLine.cpp
    src/parseline/toParseLine.cpp
    )

add_library(hnparser ${SOURCES} ${HEADERS})
