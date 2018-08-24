#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T16:20:06
#
#-------------------------------------------------

include(../udpclient.pri)
include(../htmllogger.pri)

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snbtests

DESTDIR = ../build

TEMPLATE = app


SOURCES += main.cpp\
        snbtests.cpp

HEADERS  += snbtests.h

FORMS    += snbtests.ui
