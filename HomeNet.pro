TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp \
        config/parser/loadfile.cpp \
        config/parser/parseblock.cpp \
        config/parser/parser.cpp \
        config/hnconfig/hnconfig.cpp

HEADERS += \
        log/log.h \
        log/logfunction.h \
        config/parser/parseblock.h \
        config/parser/parser.h \
        config/hnconfig/hnconfig.h
