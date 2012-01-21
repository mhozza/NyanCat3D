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

using namespace std;


ScoreModel::ScoreModel(int x, int y)
{
  this->x = x;
  this->y = y;
  float width, height;
  bool alpha;
  GLubyte * img;
  Utils::loadPngImage("graphics/numbers.png",width,height,alpha,&img);
  //todo skontrolovat return val, rozmery

  GLubyte font[10][192];
  for(int i = 0;i<10;i++)
  {
    for(int j=0;j<16;j++)
    {
      for(int k = 0;k<12;k++)
      {
        font[i][12*j+k] = img[120*j+12*i+k];
      }
    }
  }
  //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  GLuint fontOffset = glGenLists (10);
  for (int i = 0; i<10; i++)
  {
    glNewList(fontOffset + i, GL_COMPILE);
    glBitmap(12, 16, 0.0, 0.0, 15.0, 0.0, font[i]);
    glEndList();
  }
  score = new int[1];
  score[0] = 0;
}

void ScoreModel::draw()
{
  glRasterPos2i(x, y);
  glPushAttrib (GL_LIST_BIT);
  glListBase(fontOffset);
  glCallLists(score_sz, GL_UNSIGNED_BYTE, (GLubyte *) score);
  glPopAttrib();
}

void ScoreModel::setScore(int score)
{
  istringstream s;
  s << score;
  delete this->score;
  score_sz = s.str().length();
  this->score = new int[score_sz];
  for(int i = 0; i<score_sz;i++)
  {
    this->score[i] = s.str()[i]-'0';
  }
}
