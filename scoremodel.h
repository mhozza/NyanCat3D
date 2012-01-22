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

#ifndef SCOREMODEL_H
#define SCOREMODEL_H

#include "model.h"
#include <GL/gl.h>

class ScoreModel : public Model
{
  GLubyte * scoreBytes;
  int score_sz;
  int x,y;
  GLuint fontOffset;
public:
  ScoreModel(int x = 0, int y = 0);
  void draw();
  void setScore(int score);
};

#endif // SCOREMODEL_H
