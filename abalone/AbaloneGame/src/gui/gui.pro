QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
include(../../config.pri)
CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hexacell.cpp \
    main.cpp \
    abalone_gui.cpp \
    marble.cpp

HEADERS += \
    abalone_gui.h \
    general_function_gui.hpp \
    hexacell.h \
    marble.h \
    point.hpp

FORMS += \
    abalone_gui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
