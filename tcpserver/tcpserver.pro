include(../tcpclient.pri)

QT       += core
QT       += network

QT       -= gui

TARGET = tcpserver
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = ../build

DEFINES += TCPSERVER_LIBRARY

SOURCES += \
    tcpserver.cpp

HEADERS += \
    tcpserver.h
