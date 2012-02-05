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

#include "selectbutton.h"

SelectButton::SelectButton(SelectGroup *parent, int x, int y)
  :Button(x,y), parent(parent)
{
  active = false;
}

void SelectButton::deactivate()
{
  active = false;
}

void SelectButton::activate()
{
  active = true;
}


void SelectButton::onClick()
{  
  parent->setCurrentButton(this);
}

void SelectButton::draw()
{
  if(active)
  {
    //glPixelTransferf(GL_RED_SCALE, 1.0);
    //glPixelTransferf(GL_GREEN_SCALE, 2.0);
    glPixelTransferf(GL_BLUE_SCALE, 0.5);
    //glPixelTransferf(GL_RED_BIAS, 0.5);
    //glPixelTransferf(GL_GREEN_BIAS, 0.5);
    //glPixelTransferf(GL_BLUE_BIAS, -0.5);
  }
  Button::draw();
  if(active)
  {
    //glPixelTransferf(GL_RED_SCALE, 1.0);
    //glPixelTransferf(GL_GREEN_SCALE, 1.0);
    glPixelTransferf(GL_BLUE_SCALE, 1.0);
    //glPixelTransferf(GL_RED_BIAS, 0.0);
    //glPixelTransferf(GL_GREEN_BIAS, 0.0);
    //glPixelTransferf(GL_BLUE_BIAS, 0.0);
  }
}

