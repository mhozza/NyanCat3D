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

#include "gameover.h"
#include "GL/glut.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

GameOver::GameOver()
{

}

void GameOver::draw()
{
  //glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);

  //glLineWidth(2.0);

  glPushMatrix();
  glColor4i(1,1,1,1);
  glTranslatef(0,0,-4);
  glScalef(0.002,0.002,.002);
  char* s = "Game Over";
  for (int i=0;i<strlen(s);i++)
     glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
  glPopMatrix();

  //glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
  //glEnable(GL_FOG);
}
