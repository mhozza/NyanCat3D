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
#include "menuroom.h"

#include <iostream>
//#include <cstring>

GameOver::GameOver(Room* parent, int score)
  :parent(parent), score(score), info(false),
    gameOverStringW(0), scoreStringW(0), infoStringW(0)
{  
  z = -10;
  speedZ = 0.2;
  gameOverString = "Game Over";
  infoString = "Press ESC to show menu";
  scoreStream << "Score: " << score;

  //zrataj sirky stringov
  for (unsigned i=0;i<gameOverString.size();i++)
     gameOverStringW+=glutStrokeWidth(GLUT_STROKE_ROMAN,gameOverString[i]);
  for (unsigned i=0;i<scoreStream.str().size();i++)
     scoreStringW+=glutStrokeWidth(GLUT_STROKE_ROMAN,scoreStream.str()[i]);
  for (unsigned i=0;i<infoString.size();i++)
     infoStringW+=glutStrokeWidth(GLUT_STROKE_ROMAN,infoString[i]);

  Keyboard::getInstance()->registerAction(this,0,27,false);
}

void GameOver::draw()
{
  //glDisable(GL_LIGHTING);
  glDisable(GL_TEXTURE_2D);

  glLineWidth(2.0);
  glPointSize(1);

  glPushMatrix();
  glColor4i(1,1,1,1);
  glPushMatrix();
  glScalef(0.004,0.004,1);
  glTranslatef(-gameOverStringW/2.0,0,-4);
  //glRotatef(30,1,0,0);
  for (unsigned i=0;i<gameOverString.size();i++)
     glutStrokeCharacter(GLUT_STROKE_ROMAN,gameOverString[i]);
  glPopMatrix();

  if(info)
  {
    glPushMatrix();
    glScalef(0.002,0.002,1);
    glTranslatef(-scoreStringW/2.0,-300,-4);
    for (unsigned i=0;i<scoreStream.str().size();i++)
      glutStrokeCharacter(GLUT_STROKE_ROMAN,scoreStream.str()[i]);
    glPopMatrix();

    glPushMatrix();
    glScalef(0.002,0.002,1);
    glTranslatef(-infoStringW/2.0,-600,-4);
    for (unsigned i=0;i<infoString.size();i++)
      glutStrokeCharacter(GLUT_STROKE_ROMAN,infoString[i]);
    glPopMatrix();
  }
  glPopMatrix();

  //glEnable(GL_LIGHTING);
  glEnable(GL_TEXTURE_2D);
  //glEnable(GL_FOG);
}

void GameOver::step()
{
  GameObject::step();
  if(z>=0)
  {
    speedZ = 0;
    info = true;
  }
}

void GameOver::action(int actionID)
{
  if (actionID==0)
  {
    Keyboard::getInstance()->clearActions();
    Renderer::getInstance()->setRoom(new MenuRoom(parent->getParent(),WINDOW_W,WINDOW_H));
  }
}
