#-------------------------------------------------
#
# Project created by QtCreator 2014-12-21T01:57:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ss
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    piosignal.cpp \
    pioslot.cpp \
    togglebutton.cpp \
    piosignals.cpp

HEADERS  += mainwindow.h \
    piofunctionwrapper.h \
    piosignal.h \
    pioslot.h \
    togglebutton.h \
    piosignals.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11


