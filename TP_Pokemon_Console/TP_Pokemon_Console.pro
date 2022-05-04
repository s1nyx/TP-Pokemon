QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        databasemanager.cpp \
        electrikpokemon.cpp \
        firepokemon.cpp \
        game.cpp \
        main.cpp \
        plantpokemon.cpp \
        pokemon.cpp \
        trainer.cpp \
        waterpokemon.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    databasemanager.h \
    electrikpokemon.h \
    firepokemon.h \
    game.h \
    plantpokemon.h \
    pokemon.h \
    trainer.h \
    waterpokemon.h
