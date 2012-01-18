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

#include "mouse.h"
#include <GL/glut.h>

//using namespace std;

Mouse * Mouse::instance = 0;

Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}
Mouse* Mouse::getInstance()
{
  if(!instance)
    instance = new Mouse();

  return instance;
}

void Mouse::mouseFuncWrapper(int button, int state, int x, int y)
{
  Mouse::getInstance()->mouseFunc(button, state, x, y);
}

void Mouse::mouseFunc(int button, int state, int x, int y)
{

}


