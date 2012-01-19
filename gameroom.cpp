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

#include "gameroom.h"
#include "nyancat.h"
#include "universe.h"

GameRoom::GameRoom(Game *parent)
  :Room(parent)
{
  //fog
  /*glEnable(GL_FOG);
  GLfloat fogColor[4] = {0.0, 0.0, 0.0, 1.0};
  glFogi (GL_FOG_MODE, GL_EXP);
  glFogfv (GL_FOG_COLOR, fogColor);
  glFogf (GL_FOG_DENSITY, 0.05);
  glHint (GL_FOG_HINT, GL_DONT_CARE);
  glFogf (GL_FOG_START, 10.0);
  glFogf (GL_FOG_END, 20.0);*/

  mode = MODE_3D;
  addObject(new NyanCat());
  addObject(new Universe(getParent()->getTextureId(0)));
}
