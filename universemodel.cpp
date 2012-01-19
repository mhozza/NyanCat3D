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

#include "universemodel.h"

UniverseModel::UniverseModel(GLuint textureId)
  :Model(textureId)
{
}

void UniverseModel::draw()
{
  glScalef(3.0,3.0,50.0);
  glColor3f(1.0, 1.0, 0.5);
  glBegin(GL_QUADS);

  glBindTexture(GL_TEXTURE_2D,textureId);
  glTexCoord2f(0,0);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(0,1);
  glVertex3f( -1.0f, -1.0f, 1.0f);
  glTexCoord2f(1,1);
  glVertex3f( -1.0f, 1.0f, 1.0f);
  glTexCoord2f(1,0);
  glVertex3f(-1.0f,1.0f, -1.0f);

  glTexCoord2f(0,0);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glTexCoord2f(0,1);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glTexCoord2f(1,1);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(1,0);
  glVertex3f(1.0f,1.0f, -1.0f);

  glTexCoord2f(0,0);
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glTexCoord2f(0,1);
  glVertex3f(1.0f, -1.0f, -1.0f);
  glTexCoord2f(1,1);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glTexCoord2f(1,0);
  glVertex3f(-1.0f,-1.0f, 1.0f);

  glTexCoord2f(0,0);
  glVertex3f(-1.0f, 1.0f, -1.0f);
  glTexCoord2f(0,1);
  glVertex3f(1.0f, 1.0f, -1.0f);
  glTexCoord2f(1,1);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glTexCoord2f(1,0);
  glVertex3f(-1.0f,1.0f, 1.0f);

  glEnd();
}
