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
#include "gameobject.h"
#include "renderer.h"

#include <GL/glut.h>
#include <iostream>

using namespace std;

Mouse * Mouse::instance = 0;

Mouse::Mouse()
  :cleared(false)
{
  motionCoords = make_pair(0,0);
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

void Mouse::motionFuncWrapper(int x, int y)
{  
  Mouse::getInstance()->motionFunc(x,y);
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
      Block b = ((*i).second.first.first)->getModel()->getBlock();
      b.x+=((*i).second.first.first)->getX();
      b.y+=((*i).second.first.first)->getY();
      int h = 600;//TODO zratat
      //ak som trafil do obdlznika
      if(x>=b.x && x<=b.x+b.width && h-y>=b.y && h-y<=b.y+b.height)
      {
        ((*i).second.first.first)->action((*i).second.first.second);
      }            
      if(cleared)
      {
        cleared = false;
        return;
      }
    }
  }
}

void Mouse::motionFunc(int x, int y)
{  
  motionCoords = make_pair(x,y);
  for(vector<pair<GameObject*,int> >::iterator i = actionsMotion.begin();i!=actionsMotion.end();i++)
  {    
    ((*i).first)->action((*i).second);
    if(cleared)
    {
      cleared = false;
      return;
    }
  }
}

void Mouse::registerAction(GameObject *object, int actionID, int button, int state, bool global)
{
  actions.insert(make_pair(make_pair(button,state),make_pair(make_pair(object,actionID),global)));  
}

void Mouse::registerAction(GameObject *object, int actionID)
{
  actionsMotion.push_back(make_pair(object,actionID));
}

void Mouse::clearActions()
{
  cleared = true;
  actions.clear();
  actionsMotion.clear();
}

pair<int,int> Mouse::getMotionCoords()
{
  return motionCoords;
}

