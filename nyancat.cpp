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

NyanCat::NyanCat()
  :GameObject(NULL,0,0,-5)
{
  this->model = new NyanCatModel();
  Keyboard::getInstance()->registerAction(this,0,'f',false);//fog
}

void NyanCat::action(int actionId)
{
  switch(actionId)
  {
  case 0:
    Game::fog = !Game::fog;
    break;
  }
}

