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

#define GL_GLEXT_PROTOTYPES
#include "GL/gl.h"
#include "GL/glext.h"

#include "asteroidmodel.h"
#include "utils.h"

#include <cmath>
#include <cstring>
#include <iostream>


using namespace std;



AsteroidModel::AsteroidModel(int textureId)
  :Model(textureId)
{
  rotationSpeed = rand()%21-10;
  float radius = 1.0;
  //create model
  //vertices
  MyVertex v0(0,-sin(3*PI/2)*radius,0,0,0);
  vertices[0] = v0;
  int ind = 1;
  for (int i = 1; i<6;i++)
  {
    int n = 4*(3-abs(i-3));
    float py = -sin(3*PI/2+i*PI/6)*radius;
    float miniradius = abs(cos(3*PI/2+i*PI/6)*radius);
    for(int j = 0;j<n;j++)
    {      
      float angle = j*(PI/(2*(3-abs(i-3))));
      float px = cos(angle)*miniradius;
      float pz = -sin(angle)*miniradius;
      MyVertex v(px,py,pz,i%2,j%2);
      vertices[ind++] = v;
    }    
  }
  MyVertex v1(0,-sin(PI/2)*radius,0,0,0);
  vertices[ind] = v1;
  //indices
  ushort t[] = {0,1,2, 0,2,3, 0,3,4, 0,4,1, 1,5,6, 1,2,6, 1,12,5, 2,6,7, 2,7,8, 2,3,8,
               3,8,9, 3,9,10, 3,4,10, 4,10,11, 4,11,12, 4,1,12, 5,13,24, 5,13,14, 5,6,14,
               6,14,15, 6,7,15, 7,15,16, 7,16,17, 7,8,17, 8,17,18, 8,9,18, 9,18,19, 9,19,20,
               9,10,20, 10,20,21, 10,11,21, 11,21,22, 11,22,23, 11,12,23, 12,23,24, 12,5,24,
               25,13,24, 25,13,14, 25,26,14, 26,14,15, 26,27,15, 27,15,16, 27,16,17, 27,28,17,
               28,17,18, 28,29,18, 29,18,19, 29,19,20, 29,30,20, 30,20,21, 30,31,21, 31,21,22,
               31,22,23, 31,32,23, 32,23,24, 32,25,24, 33,25,26, 33,34,26, 33,32,25, 34,26,27,
               34,27,28, 34,35,28, 35,28,29, 35,29,30, 35,36,30, 36,30,31, 36,31,32, 36,33,32,
               37,33,34, 37,34,35, 37,35,36, 37,36,33 };
  memcpy(index,t,sizeof(t));

  width = height = depth = 2*radius;
  x = y = z = -radius;
}

void AsteroidModel::draw()
{
  glRotatef(rotationAngle,0,1,0);
  glEnableClientState(GL_VERTEX_ARRAY);  
  glVertexPointer(3, GL_FLOAT, sizeof(MyVertex), &vertices[0].x);
  glEnableClientState(GL_NORMAL_ARRAY);
  glNormalPointer(GL_FLOAT,sizeof(MyVertex),&vertices[0].nx);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer(2, GL_FLOAT,sizeof(MyVertex), &vertices[0].tx);  
  glBindTexture(GL_TEXTURE_2D,textureId);
  glDrawRangeElements(GL_TRIANGLES, 0, 37, 216, GL_UNSIGNED_SHORT, index);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void AsteroidModel::rotate()
{
  rotationAngle+=rotationSpeed;
  rotationAngle%=360;
}
