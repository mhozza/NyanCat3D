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

#include "renderer.h"
#include <GL/glut.h>
#include "gameobject.h"
#include <vector>

using namespace std;

Renderer * Renderer::instance = 0;

Renderer::Renderer()
{
  this->actualRoom = NULL;
}

Renderer::~Renderer()
{
  if(actualRoom!=NULL)
  {
    delete actualRoom;
  }
}

void Renderer::renderWrapper()
{
  Renderer::getInstance()->render();
}

void Renderer::reshapeWrapper(int w, int h)
{
  Renderer::getInstance()->reshape(w,h);
}


Renderer* Renderer::getInstance()
{
  if(!instance)
    instance = new Renderer();

  return instance;
}

void Renderer::render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  vector<GameObject*> objects = actualRoom->getObjects();
  for(unsigned i = 0;i<objects.size();i++)
  {
    GameObject * obj = objects[i];
    glPushMatrix();
    glTranslatef(obj->getX(), obj->getY(), obj->getZ());
    obj->getModel()->draw();
    glPopMatrix();
  }

  /*glTranslatef(-2.0f, 0.0f, -6.0f);

  glColor3f(1.0, 1.0, 1.0);
  glutWireCube(3.0);

  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_TRIANGLES);
     glVertex3f( 0.0f, 1.0f, 0.0f);
     glVertex3f(-1.0f,-1.0f, 0.0f);
     glVertex3f( 1.0f,-1.0f, 0.0f);
  glEnd();

  glTranslatef(4.0f,0.0f,0.0f);

  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
     glVertex3f(-1.0f, 1.0f, 0.0f);
     glVertex3f( 1.0f, 1.0f, 0.0f);
     glVertex3f( 1.0f,-1.0f, 0.0f);
     glVertex3f(-1.0f,-1.0f, 0.0f);
  glEnd();*/

  glutSwapBuffers();
}

void Renderer::reshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);                        // Budeme menit projekcnu maticu (transformaciu)
  glLoadIdentity();                                   // Vynulovanie

  if (h == 0)
  h = 1;
  gluPerspective(80, (float)w/(float)h, 1.0, 5000.0); // Chceme perspektivu
}

void Renderer::setRoom(Room * room)
{
  if(actualRoom!=NULL)
  {
    delete actualRoom;
  }
  this->actualRoom = room;
}
