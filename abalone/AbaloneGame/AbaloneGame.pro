TEMPLATE = subdirs

SUBDIRS += \
    src/abalonecore \
    src/console \
    src/gui \
    test

src-console= src/abalonecore

OTHER_FILES+=\config.pri
\Doxyfile
CONFIG+=ordored
