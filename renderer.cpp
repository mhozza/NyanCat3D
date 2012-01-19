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
  glClearColor(actualRoom->getBackgroundColor().red,
               actualRoom->getBackgroundColor().green,
               actualRoom->getBackgroundColor().blue,
               actualRoom->getBackgroundColor().alpha);
  glClearDepth(1.0f);

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

  glutSwapBuffers();
}

void Renderer::reshape(int w, int h)
{
  //resetView(w,h);
  glutReshapeWindow(WINDOW_W, WINDOW_H);
}

void Renderer::resetView(int w, int h)
{
  if (h == 0) h = 1;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);                        // Budeme menit projekcnu maticu (transformaciu)
  glLoadIdentity();                                   // Vynulovanie
  if(actualRoom->getMode()==MODE_2D)
    glOrtho (0.0, w, 0.0, h, -1.0, 1.0);                // Rovnobezne pravouhle premietanie
  else
    gluPerspective(100, (float)w/(float)h, 1.0f, 5000.0f); // Chceme perspektivu

  glMatrixMode(GL_MODELVIEW);                         // Vratime sa spat k modelview matici
  glLoadIdentity();                                   // A vynulujeme ju
  width = w;
  height = h;
}

void Renderer::setRoom(Room * room)
{
  if(actualRoom!=NULL)
  {
    delete actualRoom;
  }
  this->actualRoom = room;
  resetView(WINDOW_W,WINDOW_H);
}
