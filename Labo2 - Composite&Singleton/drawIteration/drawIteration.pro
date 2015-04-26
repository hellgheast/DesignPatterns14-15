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
    segment.cpp \
    widget.cpp \
    mainwindow.cpp

HEADERS  += \
    fractal.h \
    segment.h \
    widget.h \
    mainwindow.h

RESOURCES += \
    scr.qrc
