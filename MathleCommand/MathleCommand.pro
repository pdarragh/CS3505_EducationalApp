#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T19:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathleCommand
TEMPLATE = app
INCLUDEPATH+=/usr/local/mysql/include
LIBS+=-L/usr/local/mysql/lib -lmysqlclient_r


SOURCES += main.cpp\
        mainwindow.cpp \
    equationgenerator.cpp \
    dialog.cpp \
    socket.cpp

HEADERS  += mainwindow.h \
    equationgenerator.h \
    dialog.h \
    socket.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    resources.qrc
