/*
 *    Copyright (C) 2012  Michal Hozza (mhozza@gmail.com)
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

#include "camera.h"
#include "game.h"
#include <cmath>
#include <iostream>

using namespace std;

Camera::Camera()
  :GameObject(NULL,0,0,0), lookAt(Point(0,0,-1)), direction(0),direction2(0)
{  

}

/*void Camera::draw()
{
  //if(!Game::paused) return;
  gluLookAt(x,y,z,lookAt.x,lookAt.y,lookAt.z,0,1,0);
  cout << x << y << z << endl;
}*/

void Camera::action(int actionId)
{
  cout << x << y << z << endl;
  float speed =0.1;
  switch(actionId)
  {
  case 0:
    x+=speed*sin(direction*PI/180);
    y+=speed*cos(direction2*PI/180);
    z+=speed*-cos(direction*PI/180);
    break;
  case 1:
    x-=speed*sin(direction*PI/180);
    y-=speed*cos(direction2*PI/180);
    z-=speed*-cos(direction*PI/180);
    break;
  case 2:
    x-=speed*sin((90+direction)*PI/180);
    z-=speed*-cos((90+direction)*PI/180);
    break;
  case 3:
    x+=speed*sin((90+direction)*PI/180);
    z+=speed*-cos((90+direction)*PI/180);
    break;
  case 4:
    direction2++;
    break;
  case 5:
    direction2--;
    break;
  case 6:
    direction--;
    break;
  case 7:
    direction++;
    break;
  }

  lookAt.x = x-speed*-sin(direction*PI/180);
  lookAt.y = y+speed*cos(direction2*PI/180);
  lookAt.z = z-speed*cos(direction*PI/180);

}
