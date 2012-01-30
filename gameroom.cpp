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

#include "gameroom.h"
#include "nyancat.h"
#include "universe.h"
#include "asteroid.h"
#include "score.h"
#include "keyboard.h"

GameRoom::GameRoom(Game *parent)
  :Room(parent)
{  
  //fog
  /*glEnable(GL_FOG);
  GLfloat fogColor[4] = {0.0, 0.0, 0.0, 1.0};
  glFogi (GL_FOG_MODE, GL_EXP);
  glFogfv (GL_FOG_COLOR, fogColor);
  glFogf (GL_FOG_DENSITY, 0.05);
  glHint (GL_FOG_HINT, GL_DONT_CARE);
  glFogf (GL_FOG_START, 10.0);
  glFogf (GL_FOG_END, 20.0);*/

  mode = MODE_3D;
  player = new NyanCat(getParent()->getTextureId(2));
  addObject(player);
  addObject(new Score());
  addObject(new Universe(getParent()->getTextureId(0),this));
  addObject(new Universe(getParent()->getTextureId(0),this,true));
  generateBlock();
}

void GameRoom::generateBlock()
{

  //pridat nahodne asteroidy
  for(int i = 0;i<20;i++)
  {
      int block_width = 6, block_height = 6, block_depth = 60;
      float x = (rand()%(100*block_width))/100.0 - block_width/2.0;
      float y = (rand()%(100*block_height))/100.0 - block_height/2.0;
      float z = block_depth+(rand()%(100*block_depth))/100.0 - block_depth/2.0;
      addObject(new Asteroid(getParent()->getTextureId(1),x,y,-z));
  }

  //pridat nahodny bonus

}


void GameRoom::timer()
{
  Room::timer();
  gluLookAt(0,0,0,player->getX(),player->getY(),player->getZ(),0,1,0);
}
