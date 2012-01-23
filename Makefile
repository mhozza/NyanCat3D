#############################################################################
# Makefile for building: NyanCat3D
# Generated by qmake (2.01a) (Qt 4.7.4) on: po jan 23 16:20:54 2012
# Project:  NyanCat3D.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile NyanCat3D.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lglut -lGLU -lpng -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
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
		keyboard.cpp \
		button.cpp \
		startbutton.cpp \
		quitbutton.cpp \
		nyancatmodel.cpp \
		universe.cpp \
		universemodel.cpp \
		asteroidmodel.cpp \
		scoremodel.cpp \
		score.cpp 
OBJECTS       = main.o \
		game.o \
		gameobject.o \
		room.o \
		gameroom.o \
		menuroom.o \
		nyancat.o \
		camera.o \
		asteroid.o \
		renderer.o \
		model.o \
		controller.o \
		settings.o \
		bitmapmodel.o \
		utils.o \
		mouse.o \
		keyboard.o \
		button.o \
		startbutton.o \
		quitbutton.o \
		nyancatmodel.o \
		universe.o \
		universemodel.o \
		asteroidmodel.o \
		scoremodel.o \
		score.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		NyanCat3D.pro
QMAKE_TARGET  = NyanCat3D
DESTDIR       = 
TARGET        = NyanCat3D

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: NyanCat3D.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile NyanCat3D.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile NyanCat3D.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/NyanCat3D1.0.0 || $(MKDIR) .tmp/NyanCat3D1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/NyanCat3D1.0.0/ && $(COPY_FILE) --parents game.h gameobject.h room.h gameroom.h menuroom.h nyancat.h camera.h asteroid.h renderer.h model.h controller.h settings.h bitmapmodel.h utils.h mouse.h keyboard.h button.h startbutton.h quitbutton.h nyancatmodel.h universe.h universemodel.h asteroidmodel.h scoremodel.h score.h .tmp/NyanCat3D1.0.0/ && $(COPY_FILE) --parents main.cpp game.cpp gameobject.cpp room.cpp gameroom.cpp menuroom.cpp nyancat.cpp camera.cpp asteroid.cpp renderer.cpp model.cpp controller.cpp settings.cpp bitmapmodel.cpp utils.cpp mouse.cpp keyboard.cpp button.cpp startbutton.cpp quitbutton.cpp nyancatmodel.cpp universe.cpp universemodel.cpp asteroidmodel.cpp scoremodel.cpp score.cpp .tmp/NyanCat3D1.0.0/ && (cd `dirname .tmp/NyanCat3D1.0.0` && $(TAR) NyanCat3D1.0.0.tar NyanCat3D1.0.0 && $(COMPRESS) NyanCat3D1.0.0.tar) && $(MOVE) `dirname .tmp/NyanCat3D1.0.0`/NyanCat3D1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/NyanCat3D1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp game.h \
		renderer.h \
		room.h \
		gameobject.h \
		model.h \
		utils.h \
		mouse.h \
		keyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

game.o: game.cpp game.h \
		renderer.h \
		room.h \
		gameobject.h \
		model.h \
		utils.h \
		mouse.h \
		keyboard.h \
		menuroom.h \
		gameroom.h \
		nyancat.h \
		camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o game.o game.cpp

gameobject.o: gameobject.cpp gameobject.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameobject.o gameobject.cpp

room.o: room.cpp room.h \
		gameobject.h \
		model.h \
		utils.h \
		game.h \
		renderer.h \
		mouse.h \
		keyboard.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o room.o room.cpp

gameroom.o: gameroom.cpp gameroom.h \
		nyancat.h \
		gameobject.h \
		model.h \
		utils.h \
		camera.h \
		room.h \
		game.h \
		renderer.h \
		mouse.h \
		keyboard.h \
		universe.h \
		asteroid.h \
		score.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o gameroom.o gameroom.cpp

menuroom.o: menuroom.cpp menuroom.h \
		room.h \
		gameobject.h \
		model.h \
		utils.h \
		game.h \
		renderer.h \
		mouse.h \
		keyboard.h \
		bitmapmodel.h \
		startbutton.h \
		button.h \
		quitbutton.h \
		score.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o menuroom.o menuroom.cpp

nyancat.o: nyancat.cpp nyancat.h \
		gameobject.h \
		model.h \
		utils.h \
		nyancatmodel.h \
		keyboard.h \
		settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nyancat.o nyancat.cpp

camera.o: camera.cpp camera.h \
		gameobject.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o camera.o camera.cpp

asteroid.o: asteroid.cpp asteroid.h \
		gameobject.h \
		model.h \
		utils.h \
		asteroidmodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o asteroid.o asteroid.cpp

renderer.o: renderer.cpp renderer.h \
		room.h \
		gameobject.h \
		model.h \
		utils.h \
		game.h \
		mouse.h \
		keyboard.h \
		settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o renderer.o renderer.cpp

model.o: model.cpp model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o model.o model.cpp

controller.o: controller.cpp controller.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o controller.o controller.cpp

settings.o: settings.cpp settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settings.o settings.cpp

bitmapmodel.o: bitmapmodel.cpp bitmapmodel.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bitmapmodel.o bitmapmodel.cpp

utils.o: utils.cpp utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o utils.o utils.cpp

mouse.o: mouse.cpp mouse.h \
		utils.h \
		gameobject.h \
		model.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mouse.o mouse.cpp

keyboard.o: keyboard.cpp keyboard.h \
		gameobject.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o keyboard.o keyboard.cpp

button.o: button.cpp button.h \
		gameobject.h \
		model.h \
		utils.h \
		mouse.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o button.o button.cpp

startbutton.o: startbutton.cpp startbutton.h \
		button.h \
		gameobject.h \
		model.h \
		utils.h \
		game.h \
		renderer.h \
		room.h \
		mouse.h \
		keyboard.h \
		bitmapmodel.h \
		gameroom.h \
		nyancat.h \
		camera.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o startbutton.o startbutton.cpp

quitbutton.o: quitbutton.cpp quitbutton.h \
		button.h \
		gameobject.h \
		model.h \
		utils.h \
		bitmapmodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o quitbutton.o quitbutton.cpp

nyancatmodel.o: nyancatmodel.cpp nyancatmodel.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nyancatmodel.o nyancatmodel.cpp

universe.o: universe.cpp universe.h \
		gameroom.h \
		nyancat.h \
		gameobject.h \
		model.h \
		utils.h \
		camera.h \
		room.h \
		game.h \
		renderer.h \
		mouse.h \
		keyboard.h \
		universemodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o universe.o universe.cpp

universemodel.o: universemodel.cpp universemodel.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o universemodel.o universemodel.cpp

asteroidmodel.o: asteroidmodel.cpp asteroidmodel.h \
		model.h \
		utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o asteroidmodel.o asteroidmodel.cpp

scoremodel.o: scoremodel.cpp scoremodel.h \
		model.h \
		utils.h \
		settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scoremodel.o scoremodel.cpp

score.o: score.cpp score.h \
		gameobject.h \
		model.h \
		utils.h \
		game.h \
		renderer.h \
		room.h \
		mouse.h \
		keyboard.h \
		scoremodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o score.o score.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

