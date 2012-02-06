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

#include "sweet.h"
#include "game.h"
#include "utils.h"

Sweet::Sweet(float x, float y, float z)
  :GameObject(NULL,x,y,z), color(0), sl("shaders/shader.vert","shaders/shader.frag")
{
  speedZ = Game::getSpeed();
}


void Sweet::draw()
{
  glDisable(GL_TEXTURE_2D);

  float r,g,b;
  Utils::hsv2rgb(color,1.0f,1.0f,r,g,b);

  /*GLfloat clr[] = {r,g,b,1};
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,clr);*/

  if(Game::shaders)
  {
    sl.bind();
  }
  glColor4f(r, g, b, 1.0);

  glTranslatef(0,0,-0.1);
  GLUquadricObj* sweet;
  sweet = gluNewQuadric();
  gluQuadricDrawStyle(sweet, GLU_FILL);
  //gluQuadricNormals(sweet,GLU_OUTSIDE);

  glScalef(0.2,0.2,0.2);

  float tr = 1.5;
  gluSphere(sweet,1,24,24);
  glTranslatef(-tr,0,0);
  glRotatef(90,0,1,0);
  gluCylinder(sweet,1,0,1,24,1);
  glTranslatef(0,0,2*tr);
  glRotatef(180,0,1,0);
  gluCylinder(sweet,1,0,1,24,1);

  //glutSolidTeapot(2.0);
  if(Game::shaders)
  {
    sl.unbind();
  }
  /*GLfloat defaultDiffuseColor[] = {0.5,0.5,0.5,1};
  glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,defaultDiffuseColor);*/
  glEnable(GL_TEXTURE_2D);


}

void Sweet::step()
{
  color+=0.01;
  if (color>=1) color = 0;
}
