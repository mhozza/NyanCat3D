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

#include "menuroom.h"
#include "bitmapmodel.h"
#include "startbutton.h"
#include "settingsbutton.h"
#include "quitbutton.h"

#include "score.h"

#define MAGIN 10

MenuRoom::MenuRoom(Game *parent, int width, int height)
  :Room(parent)
{
  mode = MODE_2D;
  //Navyrabam si objekty
  //background
  bgcolor.setColor(1.0/255,51.0/255,102.0/255);
  //main logo
  BitmapModel * logo = new BitmapModel("graphics/logo.png");  
  addObject(new GameObject(logo,(width-logo->getBlock().width)/2,height-logo->getBlock().height,0));
  //buttons
  //start
  addObject(new StartButton(30, 300, getParent()));
  //settins
  addObject(new SettingsButton(30, 200));
  //quit
  addObject(new QuitButton(30,100));
  //addObject(new Score());
}

MenuRoom::~MenuRoom()
{

}
