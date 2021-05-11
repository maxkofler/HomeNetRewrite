QMAKE_CXXFLAGS += -I/usr/include/python3.9
QMAKE_CXXFLAGS += -I/usr/include/python3.9
QMAKE_LINK += -lpython3.9
TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        homenet/hndrivers/fetchDrivers.cpp \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp \
        parser/loadfile.cpp \
        parser/parseblock.cpp \
        parser/parser.cpp \
        #HomeNet
        homenet/homenet.cpp \
        homenet/hnconfig/hnconfig.cpp \
        #HNPython
        homenet/hnpython/hnpython.cpp \
        homenet/hnpython/pymodule/pymodule.cpp \
        #HomeNetDrivers
        homenet/hndrivers/hndriver/hndriver.cpp \
        homenet/hndrivers/hndrivers.cpp \
        homenet/hnvalue/hnvalue.cpp
        #Weathersens
        #weathersens/weathersens.cpp \
        #weathersens/wsconfig/wsconfig.cpp \
        #weathersens/wsdriverlist/wsdriver/wsdriver.cpp \
        #weathersens/wsvalue/wsvalue.cpp \
        #weathersens/wsdriverlist/wsdriverlist.cpp \
        #weathersens/wssyncloop.cpp

HEADERS += \
        log/log.h \
        log/logfunction.h \
        parser/parseblock.h \
        parser/parser.h \
        #HomeNet
        homenet/homenet.h \
        homenet/hnconfig/hnconfig.h \
        #HNPython
        homenet/hnpython/hnpython.h \
        homenet/hnpython/pymodule/pymodule.h \
        #HomeNetDrivers
        homenet/hndrivers/hndriver/hndriver.h \
        homenet/hndrivers/hndrivers.h \
        homenet/hnvalue/hnvalue.h
        #Weathersens
        #weathersens/weathersens.h \
        #weathersens/wsconfig/wsconfig.h \
        #weathersens/wsdriverlist/wsdriver/wsdriver.h \
        #weathersens/wsvalue/wsvalue.h \
        #weathersens/wsdriverlist/wsdriverlist.h
