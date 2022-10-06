TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(../../config.pri)

HEADERS += \
    Controller.h \
    View.h

SOURCES += \
    Controller.cpp \
    View.cpp \
    main.cpp
