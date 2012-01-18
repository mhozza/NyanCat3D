#-------------------------------------------------
#
# Project created by QtCreator 2011-12-02T14:03:33
#
#-------------------------------------------------

QT       +=

TARGET = NyanCat3D

SOURCES += main.cpp\        
    game.cpp \
    gameobject.cpp \
    room.cpp \
    gameroom.cpp \
    menuroom.cpp \
    nyancat.cpp \
    camera.cpp \
    asteroid.cpp \
    renderer.cpp \
    model.cpp \
    controller.cpp \
    settings.cpp \
    bitmapmodel.cpp \
    utils.cpp \
    mouse.cpp \
    keyboard.cpp

HEADERS  += \
    game.h \
    gameobject.h \
    room.h \
    gameroom.h \
    menuroom.h \
    nyancat.h \
    camera.h \
    asteroid.h \
    renderer.h \
    model.h \
    controller.h \
    settings.h \
    bitmapmodel.h \
    utils.h \
    mouse.h \
    keyboard.h

LIBS += -lglut -lGLU -lpng
