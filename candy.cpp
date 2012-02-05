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

#include "candy.h"
#include "game.h"

Candy::Candy(GLuint textureID, float x, float y, float z)
  :GameObject(NULL,x,y,z), textureId(textureID), rot(0)
{
  speedZ = Game::getSpeed();
}

void Candy::draw()
{
  glColor4i(1,1,1,1);
  glBindTexture(GL_TEXTURE_2D,textureId);
  glTranslatef(0,0,-0.1);
  GLUquadricObj* candy;
  candy = gluNewQuadric();
  gluQuadricDrawStyle(candy, GLU_FILL);
  gluQuadricNormals(candy,GLU_OUTSIDE);
  gluQuadricTexture(candy,true);


  gluCylinder(candy, 0.4, 0.4, 0.2, 24, 1);
  glPushMatrix();
  glRotatef(rot,0,0,1);
  gluDisk(candy,0,0.4,24,1);
  glPopMatrix();
  glTranslatef(0,0,0.2);
  glPushMatrix();
  glRotatef(rot,0,0,1);
  gluDisk(candy,0,0.4,24,1);
  glPopMatrix();

  glDisable(GL_TEXTURE_2D);

  glTranslatef(0,-0.4,-0.1);
  glRotatef(90,1,0,0);
  gluCylinder(candy, 0.04, 0.04, 1, 6, 1);

  glEnable(GL_TEXTURE_2D);
}

void Candy::step()
{
  rot+=12;
  rot%=360;
}
