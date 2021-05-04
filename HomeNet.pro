QMAKE_CXXFLAGS += -I/usr/include/python3.9
QMAKE_CXXFLAGS += -I/usr/include/python3.9
QMAKE_LINK += -lpython3.9
TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        homenet/hnpython/hnpython.cpp \
        homenet/hnpython/pymodule/pymodule.cpp \
        log/log.cpp \
        log/logfunction.cpp \
        main.cpp \
        parser/loadfile.cpp \
        parser/parseblock.cpp \
        parser/parser.cpp \
        #HomeNet
        homenet/homenet.cpp \
        homenet/hnconfig/hnconfig.cpp \
        #Weathersens
        weathersens/weathersens.cpp \
        weathersens/wsconfig/wsconfig.cpp \
        weathersens/wsdriverlist/wsdriver/wsdriver.cpp \
        weathersens/wsdriverlist/wsdriver/wsvalue.cpp \
        weathersens/wsdriverlist/wsdriverlist.cpp

HEADERS += \
        homenet/hnpython/hnpython.h \
        homenet/hnpython/pymodule/pymodule.h \
        log/log.h \
        log/logfunction.h \
        parser/parseblock.h \
        parser/parser.h \
        #HomeNet
        homenet/homenet.h \
        homenet/hnconfig/hnconfig.h \
        #Weathersens
        weathersens/weathersens.h \
        weathersens/wsconfig/wsconfig.h \
        weathersens/wsdriverlist/wsdriver/wsdriver.h \
        weathersens/wsdriverlist/wsdriver/wsvalue.h \
        weathersens/wsdriverlist/wsdriverlist.h
