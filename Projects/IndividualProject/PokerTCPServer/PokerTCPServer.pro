#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T23:05:59
#
#-------------------------------------------------

QT += core sql
QT += network
QT += widgets
QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokerTCPServer
TEMPLATE = app


SOURCES += main.cpp \
    pokerserver.cpp \
    pokersocket.cpp

HEADERS  += \
    pokerserver.h \
    pokersocket.h

FORMS    +=
