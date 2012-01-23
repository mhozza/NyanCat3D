/*
 *    Copyright (C) 2011-2012  Michal Hozza (mhozza@gmail.com)
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

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "gameobject.h"
#include <map>

using namespace std;


class Keyboard
{
  static Keyboard* instance;
  Keyboard();
  int width, height;
  multimap<unsigned char, pair<GameObject*, int> > actions;
  multimap<int, pair<GameObject*, int> > actionsSpecial;
public:
  static Keyboard* getInstance();
  static void keyboardFuncWrapper(unsigned char key, int x, int y);
  static void keyboardSpecialFuncWrapper(int key, int x, int y);
  void keyboardFunc(unsigned char key, int x, int y);
  void keyboardSpecialFunc(int key, int x, int y);
  void RegisterAction(GameObject * object, int actionID, int key, bool special);
  ~Keyboard();
};

#endif // KEYBOARD_H
