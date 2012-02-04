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
#include "gameoverroom.h"
#include "rainbow.h"
#include "universe.h"
#include "asteroid.h"
#include "keyboard.h"

#include <typeinfo>
#include <iostream>

#include "scorebonus.h"
#define BONUS_COUNT 1

GameRoom::GameRoom(Game *parent)
  :Room(parent)
{
  mode = MODE_3D;
  player = new NyanCat(getParent()->getTextureId(2));
  addObject(player);
  addObject(new Rainbow(player, -0.03,30));
  score = new Score();
  addObject(score);
  addObject(new Universe(getParent()->getTextureId(0),this));
  addObject(new Universe(getParent()->getTextureId(0),this,true));
  generateBlock();
}

void GameRoom::generateBlock()
{

  //pridat nahodne asteroidy
  int block_width = 6, block_height = 6, block_depth = 60;
  for(int i = 0;i<20;i++)
  {
      float x = (rand()%(100*block_width))/100.0 - block_width/2.0;
      float y = (rand()%(100*block_height))/100.0 - block_height/2.0;
      float z = block_depth+(rand()%(100*block_depth))/100.0 - block_depth/2.0;
      addObject(new Asteroid(getParent()->getTextureId(1),x,y,-z));
  }

  //pridat nahodny bonus
  float x = (rand()%(100*block_width))/100.0 - block_width/2.0;
  float y = (rand()%(100*block_height))/100.0 - block_height/2.0;
  float z = block_depth+(rand()%(100*block_depth))/100.0 - block_depth/2.0;

  int bonusNumber = rand()%BONUS_COUNT;
  GameObject * bonus;
  switch(bonusNumber)
  {
  case 0:
    bonus = new ScoreBonus(getParent()->getTextureId(3),x,y,-z);
    break;
  }
  addObject(bonus);
}


void GameRoom::timer()
{
  Room::timer();  
  //check collisions  
  for(int i = 0;i<getObjects().size();i++)
  {
    GameObject *obj =  getObjects().at(i);
    if(obj->getZ()<-7) continue;//bulharska konstanta

    //Nyan cat vs Asteroid
    Asteroid a(0,0,0,0);
    if(typeid(*obj) == typeid(a))
    {      
      Block playerRect = player->getModel()->getRect();
      playerRect.x+=player->getX();
      playerRect.y+=player->getY();
      playerRect.z+=player->getZ();
      if(Collisions::rect2sphere(playerRect,obj->getX(),obj->getY(),obj->getZ(),obj->getModel()->getRect().width/2))
      {
        Renderer::getInstance()->setRoom(new GameOverRoom(getParent(),score->getScore()));
        return;
      }
    }
  }
}
