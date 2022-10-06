TEMPLATE = app
CONFIG -= qt
CONFIG -= app_bundle
CONFIG += console

include(../config.pri)

SOURCES +=     main.cpp     tst_game_test.cpp \
    board_test.cpp \
    player_test.cpp \
    position_test.cpp

HEADERS += \
    catch.hpp
