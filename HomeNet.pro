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
        #HomeNet
        homenet/homenet.cpp \
        homenet/hnconfig/hnconfig.cpp \
        #Weathersens
        weathersens/weathersens.cpp

HEADERS += \
        log/log.h \
        log/logfunction.h \
        config/parser/parseblock.h \
        config/parser/parser.h \
        #HomeNet
        homenet/homenet.h \
        homenet/hnconfig/hnconfig.h \
        #Weathersens
        weathersens/weathersens.h
