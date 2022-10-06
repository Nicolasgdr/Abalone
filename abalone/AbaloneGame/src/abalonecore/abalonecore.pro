CONFIG -= qt

TEMPLATE = lib
CONFIG += sharelib

include(../../config.pri)
HEADERS += \
    AbaPro.hpp \
    Board.h \
    Color.h \
    Direction.h \
    Game.h \
    Marble.hpp \
    Player.hpp \
    Position.hpp \
    Square.hpp \
    State.h \
    Type.h \
    general_function.hpp

SOURCES += \
    Board.cpp \
    Game.cpp

DISTFILES += \
    abalonecore.pri
