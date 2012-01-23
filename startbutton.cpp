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

#include "startbutton.h"
#include "bitmapmodel.h"
#include "renderer.h"
#include "gameroom.h"
#include <iostream>

using namespace std;

StartButton::StartButton(int x, int y, Game * game)
  :Button(x,y)
{
  this->setModel(new BitmapModel("graphics/start.png"));
  this->game = game;
}

void StartButton::onClick()
{
  //zmaz akcie
  Mouse::getInstance()->clearActions();
  Keyboard::getInstance()->clearActions();

  //zapni hru
  Renderer::getInstance()->setRoom(new GameRoom(game));
}
