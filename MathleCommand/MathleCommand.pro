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
    dialog.cpp

HEADERS  += mainwindow.h \
    equationgenerator.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Box2D/release/ -lBox2D
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Box2D/debug/ -lBox2D
else:unix: LIBS += -L$$PWD/Box2D/ -lBox2D

INCLUDEPATH += $$PWD/Box2D
DEPENDPATH += $$PWD/Box2D

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Box2D/release/libBox2D.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Box2D/debug/libBox2D.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Box2D/release/Box2D.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Box2D/debug/Box2D.lib
else:unix: PRE_TARGETDEPS += $$PWD/Box2D/libBox2D.a
