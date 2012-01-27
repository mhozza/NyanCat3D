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

#include "nyancatmodel.h"
#include "utils.h"

//#define BUFFER_OFFSET(i) ((char *)NULL + (i))


NyanCatModel::NyanCatModel()
{
  MyVertex vertices[32];

  /*vertices[0].setParams(1,0,0.068);
  vertices[1].setParams(1,0,0.308);
  vertices[2].setParams(1,0.090,0.308);
  vertices[3].setParams(1,0.126,0.068);*/

  vertices[0].setParams(0.068,0,1);
  vertices[1].setParams(0.308,0,1);
  vertices[2].setParams(0.308,-0.090,1);
  vertices[3].setParams(0.068,-0.126,1);
  vertices[4].setParams(0.353,-0.055,1);
  vertices[5].setParams(0.365,-0.067,1);
  vertices[6].setParams(0.365,-0.113,1);
  vertices[7].setParams(0.365,-0.170,1);
  vertices[8].setParams(0.341,-0.204,1);
  vertices[9].setParams(0.284,-0.204,1);
  vertices[10].setParams(0.274,-0.204,1);
  vertices[11].setParams(0.227,-0.204,1);
  vertices[12].setParams(0.158,-0.204,1);
  vertices[13].setParams(0.114,-0.204,1);


  glGenBuffers(1, &VertexVBOID);
  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0].x, GL_STATIC_DRAW);

  GLushort indices[] = {0,1,2,3, 2,4,5,6, 6,7,10,11, 7,8,9,10, 2,6,11,12, 2,3,13,12};
  indexSize = sizeof(indices)/sizeof(GLushort);

  cout << indexSize << endl;

  glGenBuffers(1, &IndexVBOID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindBuffer( GL_ARRAY_BUFFER, NULL );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
}

void NyanCatModel::draw()
{  
  glDisable(GL_TEXTURE_2D);
  //glDisable(GL_LIGHTING);
  //glColor3f(1.0, 1.0, 1.0);
  //glutWireCube(1.0);
  glTranslatef(0,0,1);
  glScalef(8,8,1);

  glEnableClientState(GL_VERTEX_ARRAY);

  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glVertexPointer( 3, GL_FLOAT, sizeof(MyVertex), (char *) NULL );       // Set The Vertex Pointer To The Vertex


  //glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, indexyVBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  glDrawElements(GL_QUADS, indexSize, GL_UNSIGNED_SHORT, (char *) NULL);
  glDisableClientState(GL_VERTEX_ARRAY);


  glBindBuffer( GL_ARRAY_BUFFER, NULL );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
  glEnable(GL_TEXTURE_2D);
  //glEnable(GL_LIGHTING);
}

NyanCatModel::~NyanCatModel()
{
  glDeleteBuffers(1, &VertexVBOID);
  glDeleteBuffers(1, &IndexVBOID);
}
