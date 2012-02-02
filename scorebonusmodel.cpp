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
  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0].x, GL_STATIC_DRAW);

  GLushort indices[] = {};
  indexSize = sizeof(indices)/sizeof(GLushort);

  glGenBuffers(1, &IndexVBOID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindBuffer( GL_ARRAY_BUFFER, NULL );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

  width = 2*0.1; height = .228*2; depth = .365*2;
  x = -width/2;  y = -height/2;  z = -depth/2;
}
