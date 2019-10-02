#-------------------------------------------------
#
# Project created by QtCreator 2019-07-28T15:25:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = medctrl
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    startform.cpp \
    mainform.cpp

HEADERS  += \
    mainwindow.h \
    startform.h \
    mainform.h

FORMS += \
    mainwindow.ui \
    startform.ui \
    mainform.ui

RESOURCES += \
    pngfile.qrc


OTHER_FILES += \
    pngresource.qrc.autosave
