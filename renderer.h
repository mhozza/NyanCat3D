/*
 *    Copyright (C) 2011-2011  Michal Hozza (mhozza@gmail.com)
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RENDERER_H
#define RENDERER_H

#define WINDOW_W 800
#define WINDOW_H 600

//#include "shader.h"
#include "room.h"
#include "camera.h"

class Room;

class Renderer //singleton
{
  static Renderer* instance;
  Room * actualRoom;
  Renderer();
  int width, height;
  Camera* camera;
  //Shader sl;
public:  
  static Renderer* getInstance();
  static void renderWrapper();
  static void reshapeWrapper(int, int);
  static void timerWrapper(int);
  void render();
  void reshape(int w, int h);
  void timer(int value);
  inline int getWidth(){return width;}
  inline int getHeight(){return height;}
  void setRoom(Room * room);
  //Room* getRoom();
  void resetView(int w, int h);
  ~Renderer();
};

#endif // RENDERER_H
