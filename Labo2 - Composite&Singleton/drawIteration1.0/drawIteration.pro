#-------------------------------------------------
#
# Project created by QtCreator 2015-03-23T14:37:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drawIteration
TEMPLATE = app


SOURCES += main.cpp\
    fractal.cpp \
    widget.cpp \
    mainwindow.cpp \
    abstractfractal.cpp \
    leaffractal.cpp \
    compositefractal.cpp

HEADERS  += \
    fractal.h \
    widget.h \
    mainwindow.h \
    abstractfractal.h \
    leaffractal.h \
    compositefractal.h

RESOURCES += \
    scr.qrc
