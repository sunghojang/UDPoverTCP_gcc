#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T13:16:01
#
#-------------------------------------------------

include(../tcpserver.pri)
include(../tcpclient.pri)
include(../udpclient.pri)
include(../htmllogger.pri)

QT       += core network gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snbgui

DESTDIR = ../build

TEMPLATE = app


SOURCES += main.cpp\
        snbgui.cpp

HEADERS  += snbgui.h

FORMS    += snbgui.ui
