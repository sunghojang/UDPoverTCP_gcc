QT       += core
QT       += network

QT       -= gui

TARGET = udpclient
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = ../build

DEFINES += UDPCLIENT_LIBRARY

SOURCES += \
    udpclient.cpp

HEADERS += \
    udpclient.h
