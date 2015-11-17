#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T07:52:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokerGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uicontroller.cpp \
    mainscene.cpp \
    pokerhelper.cpp \
    pokerpushbutton.cpp \
    pokercardtable.cpp

HEADERS  += mainwindow.h \
    uicontroller.h \
    mainscene.h \
    pokerhelper.h \
    pokerpushbutton.h \
    pokercardtable.h


FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc \
    configuration.qrc


