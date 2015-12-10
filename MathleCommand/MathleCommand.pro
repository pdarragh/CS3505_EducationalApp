#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T19:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathleCommand
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    equationgenerator.cpp \
    dialog.cpp \
    unenrollwarning.cpp

HEADERS  += mainwindow.h \
    equationgenerator.h \
    dialog.h \
    unenrollwarning.h

FORMS    += mainwindow.ui \
    dialog.ui \
    unenrollwarning.ui

RESOURCES += \
    resources.qrc
