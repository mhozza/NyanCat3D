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

#include "room.h"
#include "mouse.h"
#include "keyboard.h"

Room::Room(Game *parent)
{
  this->parent = parent;
  //zmaz akcie
  Mouse::getInstance()->clearActions();
  Keyboard::getInstance()->clearActions();
}

Room::~Room()
{

}

vector<GameObject*> Room::getObjects()
{
  return objects;
}

void Room::addObject(GameObject* object)
{
  if(object!=NULL)
    objects.push_back(object);
}

ColorRGBAf Room::getBackgroundColor()
{
  return bgcolor;
}

int Room::getMode()
{
  return mode;
}

Game * Room::getParent()
{
  return parent;
}

void Room::timer()
{
  //if(Game::paused) return;
  for(unsigned i=0;i<objects.size();i++)
  {
    objects[i]->move();
    objects[i]->step();
  }
}

void Room::removeObjects(vector<bool> objectIndices)
{
  unsigned j = 0;
  for(unsigned i = 0; i<objects.size(); i++)
  {
    if(objectIndices[i])
    {
      delete objects[i];
    }
    else
    {
      objects[j]=objects[i];
      j++;
    }
  }
  objects.resize(j);
}
