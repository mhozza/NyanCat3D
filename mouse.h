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

#ifndef MOUSE_H
#define MOUSE_H

#include "utils.h"
#include "gameobject.h"
#include <map>
#include <vector>

using namespace std;

class Mouse  //singleton
{
  static Mouse* instance;
  Mouse();
  int width, height;
  multimap<pair<int,int>,pair<pair<GameObject*,int>,bool> > actions;
  vector<pair<GameObject*,int> > actionsMotion;
  pair<int,int> motionCoords;
  bool cleared;
public:
  static Mouse* getInstance();
  static void mouseFuncWrapper(int button, int state, int x, int y);
  static void motionFuncWrapper(int x, int y);
  void mouseFunc(int button, int state, int x, int y);
  void motionFunc(int x, int y);
  void registerAction(GameObject * object, int actionID, int button, int state, bool global);
  void registerAction(GameObject * object, int actionID);
  void clearActions();
  pair<int,int> getMotionCoords();
  ~Mouse();
};

#endif // MOUSE_H
