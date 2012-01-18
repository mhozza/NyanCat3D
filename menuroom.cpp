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
#include "quitbutton.h"

#define MAGIN 10

MenuRoom::MenuRoom(int width, int height)
{
  //Navyrabam si objekty
  //background
  bgcolor.setColor(1.0/255,51.0/255,102.0/255);
  //main logo
  BitmapModel * logo = new BitmapModel("graphics/logo.png");  
  addObject(new GameObject(logo,(width-logo->getRect().width)/2,height-logo->getRect().height,0));
  //buttons
  //start
  addObject(new StartButton(30,300));
  /*//settins
  BitmapModel * settings = new BitmapModel("graphics/settings.png");
  addObject(new GameObject(settings,(width-settings->getWidth())/2,height-logo->getHeight()-2*MAGIN-start->getWidth()-settings->getWidth(),0));*/
  //quit
  addObject(new QuitButton(30,100));

}

MenuRoom::~MenuRoom()
{

}
