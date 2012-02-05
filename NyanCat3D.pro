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
    asteroid.cpp \
    renderer.cpp \
    model.cpp \
    bitmapmodel.cpp \
    utils.cpp \
    mouse.cpp \
    keyboard.cpp \
    button.cpp \
    startbutton.cpp \
    quitbutton.cpp \
    nyancatmodel.cpp \
    universe.cpp \
    universemodel.cpp \
    asteroidmodel.cpp \
    scoremodel.cpp \
    score.cpp \
    rainbow.cpp \
    gameoverroom.cpp \
    gameover.cpp \
    scorebonus.cpp \
    scorebonusmodel.cpp \
    settingsbutton.cpp

HEADERS  += \
    game.h \
    gameobject.h \
    room.h \
    gameroom.h \
    menuroom.h \
    nyancat.h \
    asteroid.h \
    renderer.h \
    model.h \
    bitmapmodel.h \
    utils.h \
    mouse.h \
    keyboard.h \
    button.h \
    startbutton.h \
    quitbutton.h \
    nyancatmodel.h \
    universe.h \
    universemodel.h \
    asteroidmodel.h \
    scoremodel.h \
    score.h \
    rainbow.h \
    gameoverroom.h \
    gameover.h \
    scorebonus.h \
    scorebonusmodel.h \
    settingsbutton.h

LIBS += -lglut -lGLU -lpng

OTHER_FILES += \
    TODO.txt \
    README
