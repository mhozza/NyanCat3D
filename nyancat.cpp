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

#include "nyancat.h"
#include "nyancatmodel.h"
#include "keyboard.h"
#include "game.h"

NyanCat::NyanCat(int textureId)
  :GameObject(NULL,0,0,-3.25)
{
  this->model = new NyanCatModel(textureId);//,-0.02,100);
  Keyboard::getInstance()->registerAction(this,0,'f',false);//fog
  Mouse::getInstance()->registerAction(this,1);//mouseMove
}

void NyanCat::action(int actionId)
{
  switch(actionId)
  {
  case 0:
    Game::fog = !Game::fog;
    break;
  case 1:
    pair<int,int> mc = Mouse::getInstance()->getMotionCoords();
    //cout << mc.first << " " << mc.second << endl;
    this->setX(6*((float)mc.first/WINDOW_W)-3);
    this->setY(-(5*((float)mc.second/WINDOW_H)-2.5));
    break;
  }
}
