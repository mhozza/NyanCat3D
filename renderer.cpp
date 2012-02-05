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
#include "gameobject.h"
#include "keyboard.h"

#include <GL/glut.h>
#include <vector>
#include <cmath>

using namespace std;

Renderer * Renderer::instance = 0;

Renderer::Renderer()
  :actualRoom(NULL), camera(new Camera())
{  
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

void Renderer::timerWrapper(int value)
{
  Renderer::getInstance()->timer(value);
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

  /*GLfloat vzd = 3, fi = 0.7f, xi = 0.7f;
  GLdouble ex = vzd*cos(fi)*cos(xi);
  GLdouble ey = vzd*sin(fi)*cos(xi);
  GLdouble ez = vzd*sin(xi);
  gluLookAt( ex, ey, ez, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f );*/

  if(actualRoom->getMode()==MODE_3D && Game::paused)
    gluLookAt(camera->getX(),camera->getY(),camera->getZ(),camera->lookAt.x,camera->lookAt.y,camera->lookAt.z,0,1,0);


  /*glBegin( GL_LINES );
  glColor3f(1.0f, 0.0f, 0.0f );glVertex3f( 0.0f, 0.0f,0.0f );glVertex3f( 100.0f, 0.0f,0.0f );
  glColor3f(0.0f, 1.0f, 0.0f );glVertex3f( 0.0f, 0.0f,0.0f );glVertex3f( 0.0f, 100.0f,0.0f );
  glColor3f(0.0f, 0.0f, 1.0f );glVertex3f( 0.0f, 0.0f,0.0f );glVertex3f( 0.0f, 0.0f,100.0f );
  glEnd();*/

  vector<GameObject*> objects = actualRoom->getObjects();
  for(unsigned i = 0;i<objects.size();i++)
  {
    GameObject * obj = objects[i];
    glPushMatrix();
    glTranslatef(obj->getX(), obj->getY(), obj->getZ());    
    obj->draw();
    glPopMatrix();    
  }

  glutSwapBuffers();
}

void Renderer::reshape(int w, int h)
{
  //resetView(w,h);
  glutReshapeWindow(WINDOW_W, WINDOW_H);
}

void Renderer::timer(int value)
{
  actualRoom->timer();
  glutTimerFunc(value,Renderer::timerWrapper, value);
}

void Renderer::resetView(int w, int h)
{
  if (h == 0) h = 1;
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);                        // Budeme menit projekcnu maticu (transformaciu)
  glLoadIdentity();                                   // Vynulovanie
  if(actualRoom->getMode()==MODE_2D)
  {
    glOrtho (0.0, w, 0.0, h, -1.0, 1.0);                // Rovnobezne pravouhle premietanie
    glDisable(GL_FOG);
  }
  else
  {
    gluPerspective(80, (float)w/(float)h, 1.0f, 100.0f); // Chceme perspektivu
    if(Game::fog)
      glEnable(GL_FOG);
  }

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

  Keyboard::getInstance()->registerAction(camera,0,'w',false);
  Keyboard::getInstance()->registerAction(camera,1,'s',false);
  Keyboard::getInstance()->registerAction(camera,2,'a',false);
  Keyboard::getInstance()->registerAction(camera,3,'d',false);
  Keyboard::getInstance()->registerAction(camera,4,GLUT_KEY_UP,true);
  Keyboard::getInstance()->registerAction(camera,5,GLUT_KEY_DOWN,true);
  Keyboard::getInstance()->registerAction(camera,6,GLUT_KEY_LEFT,true);
  Keyboard::getInstance()->registerAction(camera,7,GLUT_KEY_RIGHT,true);

  resetView(WINDOW_W,WINDOW_H);
}

/*Room* Renderer::getRoom()
{
  return this->actualRoom;
}*/
