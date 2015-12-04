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

include(GameWidget/GameWidget.pri)

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Build/Box2D/release/ -lBox2D.2.3.2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Build/Box2D/debug/ -lBox2D.2.3.2
else:unix: LIBS += -L$$PWD/Build/Box2D/ -lBox2D.2.3.2

INCLUDEPATH += $$PWD/Box2D
DEPENDPATH += $$PWD/Box2D
