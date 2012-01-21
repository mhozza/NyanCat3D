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

#include "asteroidmodel.h"
#include <cmath>
#include "GL/gl.h"

#include <cstring>
#include <iostream>

using namespace std;

#define PI 3.1415

AsteroidModel::AsteroidModel(int textureId)
  :Model(textureId)
{
  cout << sizeof(MyVertex) << endl;

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
      float angle = j*(PI/(2*i));
      float px = cos(angle)*miniradius;
      float pz = -sin(angle)*miniradius;
      MyVertex v(px,py,pz,i%2,j%2);
      vertices[ind++] = v;
    }
    //cout << ind << endl;
  }
  MyVertex v1(0,-sin(PI/2)*radius,0,1,1);
  vertices[ind] = v1;
  cout << ind << endl;

  //index
  /*ind = 1;
  int ind2 = 0;
  for (int i = 1; i<6;i++)
  {
    int n = 4*(3-abs(i-3));
    int np = 4*(3-abs(i-4));
    int nn = 4*(3-abs(i-2));
    int startind = ind;
    for(int j = 0;j<n;j++)
    {
      if(i==1)
      {
        index[ind2++] = 0;
      }
      else
      {
        //index[ind2++] = startind+(ind-startind+1)%np;
        index[ind2++] = 0;
      }
      index[ind2++] = ind;
      index[ind2++] = startind+(j+1)%n;

      index[ind2++] = ind;
      index[ind2++] = startind+(j+1)%n;
      if(i==6)
      {
        index[ind2++] = 37;
      }
      else
      {
        index[ind2++] = startind+n+2*j;
        //index[ind2++] = startind+(ind-startind+1)%nn;
      }
      ind++;
    }
  }
  cout << ind2 << endl;*/
  //rucne
  ushort t[] = {0,1,2, 0,2,3, 0,3,4, 0,4,1, 1,5,6, 1,2,6, 1,12,5, 2,6,7, 2,7,8, 2,3,8,
               3,8,9, 3,9,10, 3,4,10, 4,10,11, 4,11,12, 4,1,12, 5,13,24, 5,13,14, 5,6,14,
               6,14,15, 6,7,15, 7,15,16, 7,16,17, 7,8,17, 8,17,18, 8,9,18, 9,18,19, 9,19,20,
               9,10,20, 10,20,21, 10,11,21, 11,21,22, 11,22,23, 11,12,23, 12,23,24, 12,5,24,
               25,13,24, 25,13,14, 25,26,14, 26,14,15, 26,27,15, 27,15,16, 27,16,17, 27,28,17,
               28,17,18, 28,29,18, 29,18,19, 29,19,20, 29,10,20, 30,20,21, 30,31,21, 31,21,22,
               31,22,23, 31,32,23, 32,23,24, 32,25,24, 33,25,26, 33,34,26, 33,32,25, 34,26,27,
               34,27,28, 34,35,28, 35,28,29, 35,29,30, 35,36,30, 36,30,31, 36,31,32, 36,33,32,
               37,33,34, 37,34,35, 37,35,36, 37,36,33 };
  memcpy(index,t,sizeof(t));
}

void AsteroidModel::draw()
{
  glColor3f(.4,.15,.01);
  //glDisable(GL_TEXTURE_2D);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, sizeof(MyVertex), &vertices[0].x);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  glTexCoordPointer(2, GL_FLOAT,sizeof(MyVertex), &vertices[0].tx);
  //glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(MyVertex), &vertices[0].color);
  glBindTexture(GL_TEXTURE_2D,textureId);
  glDrawRangeElements(GL_TRIANGLES, 0, 37, 216, GL_UNSIGNED_SHORT, index);
  //glEnable(GL_TEXTURE_2D);
}
