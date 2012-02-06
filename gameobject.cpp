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

#include "gameobject.h"
#include "game.h"

#include <iostream>

using namespace std;

GameObject::GameObject(Model * model = NULL, float x = 0.0f, float y = 0.0f, float z= 0.0f)
{
  speedX = 0; speedY = 0; speedZ = 0;
  this->model = NULL;
  setModel(model);
  setX(x);
  setY(y);
  setZ(z);
}


GameObject::~GameObject()
{
  if (model!=NULL)
    delete model;
}

void GameObject::move()
{
  if(Game::paused) return;
  x+=speedX;
  y+=speedY;
  z+=speedZ;
}

Model * GameObject::getModel()
{  
  return model;
}

void GameObject::setModel(Model* model)
{
  if (this->model!=NULL)
    delete this->model;
  this->model = model;  
}

void GameObject::draw()
{
  if(this->getModel()!=NULL)
    this->getModel()->draw();
}
