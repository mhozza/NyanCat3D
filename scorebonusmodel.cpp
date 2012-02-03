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

#include "scorebonusmodel.h"

#include <iostream>

using namespace std;

ScoreBonusModel::ScoreBonusModel()
{
  MyVertex vertices[8];

  for(int x = 0;x<=1;x++)
  {
    for(int y = 0;y<=1;y++)
    {
      for(int z = 0;z<=1;z++)
      {
        vertices[4*x+2*y+z].setParams(x,y,z);
      }
    }
  }

  /*
  for(int i = 0;i<sizeof(vertices)/sizeof(MyVertex);i++)
  {
    //vertices[i].makeTexturePoints(0,0,MAP_Z,MAP_Y);
    //vertices[i].makeNormals(0,0.114,-0.188);
  }
  */

  glGenBuffers(1, &VertexVBOID);
  cout << VertexVBOID << endl;
  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0].x, GL_STATIC_DRAW);

  GLushort indices[] = {0,1,3,2, 0,1,5,4, 2,3,7,6, 4,5,7,6, 0,4,6,2, 1,5,7,3};
  indexSize = sizeof(indices)/sizeof(GLushort);

  glGenBuffers(1, &IndexVBOID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindBuffer( GL_ARRAY_BUFFER, NULL );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

  /*width = 2*0.1; height = .228*2; depth = .365*2;
  x = -width/2;  y = -height/2;  z = -depth/2;*/
}

ScoreBonusModel::~ScoreBonusModel()
{
  glDeleteBuffers(1, &VertexVBOID);
  glDeleteBuffers(1, &IndexVBOID);
}

void ScoreBonusModel::draw()
{
  glDisable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE);

  glColor4i(1,1,1,1);

  glScalef(2,2,2);
  glTranslatef(-1,-1,-1);

  glEnableClientState(GL_VERTEX_ARRAY);
  //glEnableClientState(GL_NORMAL_ARRAY);
  //glEnableClientState(GL_TEXTURE_COORD_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glVertexPointer( 3, GL_FLOAT, sizeof(MyVertex), BUFFER_OFFSET(0) );
  glNormalPointer(GL_FLOAT,sizeof(MyVertex),BUFFER_OFFSET((5*sizeof(float))));
  glTexCoordPointer(2, GL_FLOAT,sizeof(MyVertex), BUFFER_OFFSET((3*sizeof(float))));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  glBindTexture(GL_TEXTURE_2D,textureId);
  glDrawElements(GL_QUADS, indexSize, GL_UNSIGNED_SHORT, (char *) NULL);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_TEXTURE_COORD_ARRAY);

  glBindBuffer( GL_ARRAY_BUFFER, NULL );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

  glEnable(GL_TEXTURE_2D);
  glDisable(GL_BLEND);

}
