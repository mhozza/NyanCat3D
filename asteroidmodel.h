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

#ifndef ASTEROIDMODEL_H
#define ASTEROIDMODEL_H

#include "model.h"

struct MyVertex
{
  float x,y,z;
  float tx,ty;
  float nx, ny, nz;
  //float padding[3];
  MyVertex()
  {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->nx = 0;
    this->ny = 0;
    this->nz = 0;
    this->tx = 0;
    this->ty = 0;
    //color = 0x9900ffff;
  }
  MyVertex(float x, float y, float z, float tx, float ty)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->nx = x;
    this->ny = y;
    this->nz = z;
    this->tx = tx;
    this->ty = ty;
    //color = 0x9900ffff;
  }
};

class AsteroidModel : public Model
{
  MyVertex vertices[38];
  ushort index[216];
public:
    AsteroidModel(int textureId);
    void draw();
};

#endif // ASTEROIDMODEL_H
