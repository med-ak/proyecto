QT -= gui
QT          += sql

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
        cliente.cpp \
    conexion.cpp


LIBS += -pthread -lz -lssl -lcrypto


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



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

HEADERS += \
    json.hpp \
    cliente.h \
    conexion.h


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
