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

#include "candy.h"
#include "sweet.h"
#include "teapot.h"
#include "fish.h"
#define DECORATION_COUNT 4

GameRoom::GameRoom(Game *parent)
  :Room(parent)
{
  mode = MODE_3D;
  //addObject(new Camera());
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

  //dekoracne objekty
  x = (rand()%(100*block_width))/100.0 - block_width/2.0;
  y = (rand()%(100*block_height))/100.0 - block_height/2.0;
  z = block_depth+(rand()%(100*block_depth))/100.0 - block_depth/2.0;

  int decorationNumber = rand()%DECORATION_COUNT;
  GameObject * decor;
  switch(decorationNumber)
  {
  case 0:
    decor = new Candy(getParent()->getTextureId(4),x,y,-z);
    break;
  case 1:
    decor = new Sweet(x,y,-z);
    break;
  case 2:
    decor = new Teapot(getParent()->getTextureId(0),x,y,-z);
    break;
  case 3:
    decor = new Fish(getParent()->getTextureId(5),x,y,-z);
    break;
  }
  addObject(decor);
}


void GameRoom::timer()
{
  Room::timer();

  vector<bool> remove;
  remove.resize(0);
  remove.resize(getObjects().size(),false);

  Universe u(0,0,0);
  Asteroid a(0,0,0,0);
  ScoreBonus sb(0,0,0,0);

  //check collisions  
  for(unsigned i = 0;i<getObjects().size();i++)
  {
    GameObject *obj =  getObjects().at(i);
    if(obj->getZ()<-10) continue;//bulharska konstanta
    if(obj->getZ()>0)
    {
      if(typeid(*obj)!=typeid(u))
      remove[i] = true;
      continue;
    }



    Block playerBlock = player->getModel()->getBlock();
    playerBlock.x+=player->getX();
    playerBlock.y+=player->getY();
    playerBlock.z+=player->getZ();

    //Nyan cat vs Asteroid
    if(typeid(*obj) == typeid(a))
    {
      if(Collisions::block2sphere(playerBlock,obj->getX(),obj->getY(),obj->getZ(),obj->getModel()->getBlock().width/2))
      {
        Renderer::getInstance()->setRoom(new GameOverRoom(getParent(),score->getScore()));
        remove[i] = true;
        return;
      }
    }
    else if(typeid(*obj)==typeid(sb))
    {
      Block objBlock = obj->getModel()->getBlock();
      Point p(obj->getX(),obj->getY(),obj->getZ());      
      objBlock+=p;      
      if(Collisions::block2block(playerBlock,objBlock))
      {
        score->add(100);
        remove[i] = true;
        //return;
      }
    }

  }

  removeObjects(remove);
}
