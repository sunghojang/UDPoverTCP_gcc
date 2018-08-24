QT       += core
QT       += network

QT       -= gui

TARGET = tcpclient
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = ../build

DEFINES += TCPCLIENT_LIBRARY

SOURCES += \
    tcpclient.cpp

HEADERS += \
    tcpclient.h
