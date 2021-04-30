QMAKE_CXXFLAGS += -I/usr/include/python3.9
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        homenet/hnpython/hnpython.cpp \
        homenet/hnpython/pymodule/pymodule.cpp \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp \
        config/parser/loadfile.cpp \
        config/parser/parseblock.cpp \
        config/parser/parser.cpp \
        #HomeNet
        homenet/homenet.cpp \
        homenet/hnconfig/hnconfig.cpp \
        #Weathersens
        weathersens/weathersens.cpp

HEADERS += \
        homenet/hnpython/hnpython.h \
        homenet/hnpython/pymodule/pymodule.h \
        log/log.h \
        log/logfunction.h \
        config/parser/parseblock.h \
        config/parser/parser.h \
        #HomeNet
        homenet/homenet.h \
        homenet/hnconfig/hnconfig.h \
        #Weathersens
        weathersens/weathersens.h
