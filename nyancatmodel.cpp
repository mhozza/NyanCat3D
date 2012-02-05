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




NyanCatModel::NyanCatModel(int textureId)
  :Model(textureId)
{
  MyVertex vertices[60];

  vertices[0].setParams(1,0,0.068);
  vertices[1].setParams(1,0,0.308);
  vertices[2].setParams(1,-0.090,0.308);
  vertices[3].setParams(1,-0.126,0.068);
  vertices[4].setParams(1,-0.055,0.353);
  vertices[5].setParams(1,-0.067,0.365);
  vertices[6].setParams(1,-0.113,0.365);
  vertices[7].setParams(1,-0.170,0.365);
  vertices[8].setParams(1,-0.204,0.341);
  vertices[9].setParams(1,-0.204,0.284);
  vertices[10].setParams(1,-0.204,0.274);
  vertices[11].setParams(1,-0.204,0.227);
  vertices[12].setParams(1,-0.204,0.158);
  vertices[13].setParams(1,-0.204,0.114);
  vertices[14].setParams(1,-0.204,0.102);
  vertices[15].setParams(1,-0.160,0.068);
  vertices[16].setParams(1,-0.194,0.068);
  vertices[17].setParams(1,-0.228,0.090);
  vertices[18].setParams(1,-0.228,0.055);
  vertices[19].setParams(1,-0.194,0.055);
  vertices[20].setParams(1,-0.228,0.114);
  vertices[21].setParams(1,-0.228,0.158);
  vertices[22].setParams(1,-0.228,0.227);
  vertices[23].setParams(1,-0.228,0.274);
  vertices[24].setParams(1,-0.228,0.284);
  vertices[25].setParams(1,-0.228,0.341);
  vertices[26].setParams(1,-0.125,0);
  vertices[27].setParams(1,-0.113,0.045);
  vertices[28].setParams(1,-0.092,0.034);
  vertices[29].setParams(1,-0.092,0);

  vertices[30].setParams(-1,0,0.068);
  vertices[31].setParams(-1,0,0.308);
  vertices[32].setParams(-1,-0.090,0.308);
  vertices[33].setParams(-1,-0.126,0.068);
  vertices[34].setParams(-1,-0.055,0.353);
  vertices[35].setParams(-1,-0.067,0.365);
  vertices[36].setParams(-1,-0.113,0.365);
  vertices[37].setParams(-1,-0.170,0.365);
  vertices[38].setParams(-1,-0.204,0.341);
  vertices[39].setParams(-1,-0.204,0.284);
  vertices[40].setParams(-1,-0.204,0.274);
  vertices[41].setParams(-1,-0.204,0.227);
  vertices[42].setParams(-1,-0.204,0.158);
  vertices[43].setParams(-1,-0.204,0.114);
  vertices[44].setParams(-1,-0.204,0.102);
  vertices[45].setParams(-1,-0.160,0.068);
  vertices[46].setParams(-1,-0.194,0.068);
  vertices[47].setParams(-1,-0.228,0.090);
  vertices[48].setParams(-1,-0.228,0.055);
  vertices[49].setParams(-1,-0.194,0.055);
  vertices[50].setParams(-1,-0.228,0.114);
  vertices[51].setParams(-1,-0.228,0.158);
  vertices[52].setParams(-1,-0.228,0.227);
  vertices[53].setParams(-1,-0.228,0.274);
  vertices[54].setParams(-1,-0.228,0.284);
  vertices[55].setParams(-1,-0.228,0.341);
  vertices[56].setParams(-1,-0.125,0);
  vertices[57].setParams(-1,-0.113,0.045);
  vertices[58].setParams(-1,-0.092,0.034);
  vertices[59].setParams(-1,-0.092,0);

  for(unsigned i = 0;i<sizeof(vertices)/sizeof(MyVertex);i++)
  {
    vertices[i].makeTexturePoints(0.376,-0.228,MAP_Z,MAP_Y);
    vertices[i].makeNormals(0,0.114,-0.188);
  }

  glGenBuffers(1, &VertexVBOID);
  glBindBuffer(GL_ARRAY_BUFFER, VertexVBOID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0].x, GL_STATIC_DRAW);

  GLushort indices[] = {0,1,2,3, 2,4,5,6, 6,7,10,11, 7,8,9,10, 2,6,11,12,
                        2,3,13,12, 3,13,14,15, 14,15,16,17, 16,17,18,19,
                        12,13,20,21, 10,11,22,23, 8,9,24,25, 3,15,26,27,
                        26,27,28,29,
                        30,31,32,33, 32,34,35,36, 36,37,40,41, 37,38,39,40,
                        32,36,41,42, 32,33,43,42, 33,43,44,45, 44,45,46,47,
                        46,47,48,49, 42,43,50,51, 40,41,52,53, 38,39,54,55,
                        33,45,56,57, 56,57,58,59,
                        0,1,31,30, 1,2,32,31, 2,4,34,32, 4,5,35,34, 5,6,36,35,
                        6,7,37,36, 7,8,38,37, 8,25,55,38, 25,24,54,55, 24,9,39,54,
                        9,10,40,39, 10,23,53,40, 23,22,52,53, 11,12,42,41, 12,21,51,42,
                        21,20,50,51, 20,13,43,50, 13,14,44,43, 14,17,47,44, 17,18,48,47,
                        18,19,49,48, 19,16,46,49, 16,15,45,46, 15,26,56,45, 26,29,59,56,
                        29,28,58,59, 28,27,57,58, 27,3,33,57, 3,0,30,33
                       };
  indexSize = sizeof(indices)/sizeof(GLushort);  

  glGenBuffers(1, &IndexVBOID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexVBOID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindBuffer( GL_ARRAY_BUFFER, 0 );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  width = 2*0.1; height = .228*2; depth = .365*2;
  x = -width/2;  y = -height/2;  z = -depth/2;  
}

void NyanCatModel::draw()
{    
  glTranslatef(0,0.114,-0.188);
  glScalef(0.1,2,-2);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_TEXTURE_COORD_ARRAY);

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

  glBindBuffer( GL_ARRAY_BUFFER, 0 );
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}

NyanCatModel::~NyanCatModel()
{
  glDeleteBuffers(1, &VertexVBOID);
  glDeleteBuffers(1, &IndexVBOID);
}

