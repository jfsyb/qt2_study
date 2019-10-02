#-------------------------------------------------
#
# Project created by QtCreator 2017-12-13T14:27:37
#
#-------------------------------------------------

QT       -= gui

TARGET = LogServer
TEMPLATE = lib

DEFINES += LOGSERVER_LIBRARY

SOURCES += logserver.cpp

HEADERS += \
    ../include/LogServer/logserver.h \
    ../include/LogServer/logserver_global.h

contains(DEFINES,arm){
DESTDIR  = ../../AM/arm_bin_debug
}
else{
DESTDIR  = ../../AM/linux_bin_debug
}
