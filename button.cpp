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

#include "button.h"
#include "mouse.h"
#include "GL/glut.h"
#include "utils.h"

Button::Button(int x, int y)
  :GameObject(NULL,x,y,0)
{  
  Mouse * m = Mouse::getInstance();
  m->registerAction(this,0,GLUT_LEFT_BUTTON,GLUT_DOWN,false);
}

void Button::action(int actionID)
{
  if(actionID==0)
  {
    onClick();
  }
}
