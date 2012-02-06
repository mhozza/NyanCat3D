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

#include "fish.h"
#include "game.h"
#include "cmath"

Fish::Fish(GLuint textureID, float x, float y, float z)
  :GameObject(NULL,x,y,z), textureId(textureID), rot(0)
{
  speedZ = Game::getSpeed();
}

void Fish::draw()
{
  glColor4i(1,1,1,1);
  glBindTexture(GL_TEXTURE_2D,textureId);
  glTranslatef(0,0,-0.1);
  GLUquadricObj* fish;
  fish = gluNewQuadric();
  gluQuadricDrawStyle(fish, GLU_FILL);
  gluQuadricTexture(fish,true);

  glScalef(0.4,-0.8,1.2);
  gluSphere(fish,1,24,24);
  glRotatef(sin(rot*PI/180)*20,0,1,0);
  glTranslatef(0,0,-1);
  glScalef(1,1,1.2);
  gluCylinder(fish,1,0,1,24,1);

}

void Fish::step()
{
  rot+=10;
}
