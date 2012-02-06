/*
 *    Copyright (C) 2012  Michal Hozza (mhozza@gmail.com)
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

#include "teapot.h"
#include "game.h"
#include "utils.h"

Teapot::Teapot(int textureId, float x, float y, float z)
  :GameObject(NULL,x,y,z), shader("shaders/envmap.vert","shaders/envmap.frag"),
    textureId(textureId)
{
  speedZ = Game::getSpeed();
}


void Teapot::draw()
{
  glDisable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,textureId);
  if(Game::shaders)
  {
    shader.bind();
  }
  glColor4f(1,1,1, 1.0);

  glTranslatef(0,0,-0.1);
  GLUquadricObj* teapot;
  teapot = gluNewQuadric();
  gluQuadricDrawStyle(teapot, GLU_FILL);

  glutSolidTeapot(0.5);

  if(Game::shaders)
  {
    shader.unbind();
  }
  glEnable(GL_TEXTURE_2D);
}


