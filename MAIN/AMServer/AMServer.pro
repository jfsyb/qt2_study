#-------------------------------------------------
#
# Project created by QtCreator 2017-11-22T16:18:51
#
#-------------------------------------------------

#QT       += core

#QT       -= gui
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

CONFIG += link_pkgconfig

TARGET = AMServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
contains(DEFINES,arm){
DESTDIR  = ../../AM/arm_bin_debug
}
else{
DESTDIR  = ../../AM/linux_bin_debug
}
