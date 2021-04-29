TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp \
        parser/loadfile.cpp \
        parser/parseblock.cpp \
        parser/parser.cpp

HEADERS += \
        log/log.h \
        log/logfunction.h \
        parser/parseblock.h \
        parser/parser.h
