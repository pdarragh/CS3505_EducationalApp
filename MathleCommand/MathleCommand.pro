#-------------------------------------------------
#
# Project created by QtCreator 2015-11-23T19:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MathleCommand
TEMPLATE = app

include(GameWidget/GameWidget.pri)

SOURCES +=\
        mainwindow.cpp \
    dialog.cpp \
    socket.cpp \
    studentresults.cpp \
    unenrollwarning.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    socket.h \
    studentresults.h \
    unenrollwarning.h

FORMS    += mainwindow.ui \
    dialog.ui \
    unenrollwarning.ui

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libs/release/ -lmysqlclient_r
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libs/debug/ -lmysqlclient_r
else:unix: LIBS += -L$$PWD/libs/ -lmysqlclient_r

INCLUDEPATH += $$PWD/libs/mysql-include
DEPENDPATH += $$PWD/libs/mysql-include
LIBS += -L$$PWD/libs/mysql

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/release/libmysqlclient_r.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/debug/libmysqlclient_r.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/libs/release/mysqlclient_r.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/libs/debug/mysqlclient_r.lib
else:unix: PRE_TARGETDEPS += $$PWD/libs/libmysqlclient_r.a
