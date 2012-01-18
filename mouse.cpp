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

#include "mouse.h"
#include <GL/glut.h>
#include "gameobject.h"
#include <iostream>

using namespace std;

Mouse * Mouse::instance = 0;

Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}
Mouse* Mouse::getInstance()
{
  if(!instance)
    instance = new Mouse();

  return instance;
}

void Mouse::mouseFuncWrapper(int button, int state, int x, int y)
{
  Mouse::getInstance()->mouseFunc(button, state, x, y);
}

void Mouse::mouseFunc(int button, int state, int x, int y)
{
  //cerr << "Klik:" << button << " " << state << endl;
  pair<multimap<pair<int,int>,pair<pair<GameObject*,int>,bool> >::iterator,
      multimap<pair<int,int>,pair<pair<GameObject*,int>,bool> >::iterator>
      r = actions.equal_range(make_pair(button,state));
  for(multimap<pair<int,int>,pair<pair<GameObject*,int>,bool> >::iterator
      i = r.first;i!=r.second;i++)
  {
    if((*i).second.second)//if global
    {
      ((*i).second.first.first)->action((*i).second.first.second);
    }
    else
    {
      //get object rect
      Rect r = ((*i).second.first.first)->getModel()->getRect();
      r.x+=((*i).second.first.first)->getX();
      r.y+=((*i).second.first.first)->getY();
      int h = 600;//TODO zratat
      cerr << x << " " << h-y << endl << r.x << " " << r.y << " " << r.x+r.width << " " << r.y+r.height << endl;
      //ak som trafil do obdlznika
      if(x>=r.x && x<=r.x+r.width && h-y>=r.y && h-y<=r.y+r.height)
      {
        ((*i).second.first.first)->action((*i).second.first.second);
      }
    }
  }
}

void Mouse::registerAction(GameObject *object, int actionID, int button, int state, bool global)
{
  actions.insert(make_pair(make_pair(button,state),make_pair(make_pair(object,actionID),global)));
  //cerr << "Reg:" << button << " " << state << endl;
}

void Mouse::clearActions()
{
  actions.clear();
}

