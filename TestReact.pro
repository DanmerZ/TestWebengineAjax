#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T21:10:12
#
#-------------------------------------------------

QT       += core gui webenginewidgets webchannel
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestReact
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    external.cpp

HEADERS  += mainwindow.h \
    external.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
