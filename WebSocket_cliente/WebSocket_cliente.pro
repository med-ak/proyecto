#-------------------------------------------------
#
# Project created by QtCreator 2020-01-16T13:42:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebSocket_cliente
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0




CONFIG += c++14

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cliente.cpp

HEADERS += \
        mainwindow.h \
        json.hpp \
    cliente.h

FORMS += \
        mainwindow.ui \
    cliente.ui
LIBS += -pthread -lz

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../compiled2/lib/release/ -lixwebsocket
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../compiled2/lib/debug/ -lixwebsocket
else:unix: LIBS += -L$$PWD/../compiled2/lib/ -lixwebsocket

INCLUDEPATH += $$PWD/../compiled2/include
DEPENDPATH += $$PWD/../compiled2/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../compiled2/lib/release/libixwebsocket.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../compiled2/lib/debug/libixwebsocket.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../compiled2/lib/release/ixwebsocket.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../compiled2/lib/debug/ixwebsocket.lib
else:unix: PRE_TARGETDEPS += $$PWD/../compiled2/lib/libixwebsocket.a
