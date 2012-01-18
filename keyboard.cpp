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

#include "keyboard.h"
#include <GL/glut.h>

//using namespace std;

Keyboard * Keyboard::instance = 0;

Keyboard::Keyboard()
{

}

Keyboard::~Keyboard()
{

}
Keyboard* Keyboard::getInstance()
{
  if(!instance)
    instance = new Keyboard();

  return instance;
}

void Keyboard::keyboardFuncWrapper(unsigned char key, int x, int y)
{
  Keyboard::getInstance()->keyboardFunc(key, x, y);
}

void Keyboard::keyboardSpecialFuncWrapper(int key, int x, int y)
{
  Keyboard::getInstance()->keyboardSpecialFunc(key, x, y);
}


void Keyboard::keyboardFunc(unsigned char key, int x, int y)
{

}

void Keyboard::keyboardSpecialFunc(int key, int x, int y)
{

}


