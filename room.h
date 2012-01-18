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

#ifndef ROOM_H
#define ROOM_H

#include "gameobject.h"
#include <vector>
#include <cstddef>
#include "utils.h"

using namespace std;

class Room
{
  vector<GameObject*> objects;
protected:
  void addObject(GameObject* object);
  ColorRGBAf bgcolor;
public:
  Room();
  ~Room();
  vector<GameObject*> getObjects();
  ColorRGBAf getBackgroundColor();

};

#endif // ROOM_H
