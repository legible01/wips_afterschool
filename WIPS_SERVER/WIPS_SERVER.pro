TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    svrsocket.cpp \
    packframes.cpp \
    mac.cpp \
    listload.cpp \
    dbmanage.cpp

LIBS += -lpcap
LIBS +=-lmysqlclient
LIBS +=-pthread

HEADERS += \
    svrsocket.h \
    mac.h \
    listload.h \
    packframes.h \
    listload.h \
    dbmanage.h
