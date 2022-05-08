QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    attackwidget.cpp \
    databasemanager.cpp \
    electrikpokemon.cpp \
    finishwidget.cpp \
    firepokemon.cpp \
    game.cpp \
    homewidget.cpp \
    main.cpp \
    plantpokemon.cpp \
    pokemon.cpp \
    trainer.cpp \
    waterpokemon.cpp \
    widget.cpp

HEADERS += \
    attackwidget.h \
    databasemanager.h \
    electrikpokemon.h \
    finishwidget.h \
    firepokemon.h \
    game.h \
    homewidget.h \
    plantpokemon.h \
    pokemon.h \
    trainer.h \
    waterpokemon.h \
    widget.h

FORMS += \
    attackwidget.ui \
    finishwidget.ui \
    homewidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
