QT       += core

QT       -= gui

TARGET = htmllogger
TEMPLATE = lib
CONFIG += staticlib

DESTDIR = ../build

DEFINES += HTMLLOGGER_LIBRARY

SOURCES += \
    htmllogger.cpp

HEADERS += \
    htmllogger.h
