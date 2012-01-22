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

#include "scoremodel.h"
#include "utils.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


ScoreModel::ScoreModel(int x, int y)
{
  this->x = x;
  this->y = y;
  float width, height;
  bool alpha;
  GLubyte *img;
  if(!Utils::loadPngImage("graphics/numbers.png",width,height,alpha,&img))
  {
    cerr << "Unable to load font: graphics/numbers.png" << endl;
  }
  //todo skontrolovat return val, rozmery

  GLubyte font[10][192];
  GLubyte bitmap[10][32];

  for(int i = 0;i<10;i++)
  {
    for(int j=0;j<16;j++)
    {
      for(int k = 0;k<12;k++)
      {
        font[i][12*j+k] = *(img+((int)width*j+12*i+k)*4);
      }
    }
  }

  for(int i = 0;i<10;i++)
  {
    int k = 0;
    for(int l = 0;l<32;l++)
    {
      GLubyte bt = 0;
      for(int j = 0; j< 8;j++)
      {
        bt |= (1-(font[i][k] & 1)) << 7-j;

        k++;
        if(k%12 == 0) break;
      }

      bitmap[i][l] = bt;
    }
  }

  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  fontOffset = glGenLists (10);


  for (int i = 0; i<10; i++)
  {
    glNewList(fontOffset + i, GL_COMPILE);
    //glColor3i(1,1,1);
    glBitmap(12, 16, 0.0, 0.0, 15.0, 0.0, bitmap[i]);
    glEndList();
  }


  scoreBytes = new GLubyte[1];
  scoreBytes[0] = 0;
}

void ScoreModel::draw()
{
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_FOG);
  glMatrixMode(GL_PROJECTION);                        // Budeme menit projekcnu maticu (transformaciu)
  glPushMatrix();
  glLoadIdentity();                                   // Vynulovanie
  glOrtho (0.0, 800, 0.0, 600, -1.0, 1.0);                // Rovnobezne pravouhle premietanie
  glRasterPos2i(x, y);
  glPushAttrib (GL_LIST_BIT);
  glListBase(fontOffset);
  glCallLists(score_sz, GL_UNSIGNED_BYTE, scoreBytes);
  glPopAttrib();
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_FOG);
}

void ScoreModel::setScore(int score)
{
  ostringstream s;
  s << score;
  delete this->scoreBytes;
  score_sz = s.str().length();
  this->scoreBytes = new GLubyte[score_sz];
  for(int i = 0; i<score_sz;i++)
  {
    this->scoreBytes[i] = s.str()[i]-'0';
  }
}
