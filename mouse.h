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

class Mouse  //singleton
{
  static Mouse* instance;
  Mouse();
  int width, height;
public:
  static Mouse* getInstance();
  static void mouseFuncWrapper(int button, int state, int x, int y);
  void mouseFunc(int button, int state, int x, int y);
  ~Mouse();
};

#endif // MOUSE_H
