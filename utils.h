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

#ifndef UTILS_H
#define UTILS_H

#include <GL/glut.h>

struct ColorRGBAf
{
  GLclampf red, green, blue, alpha;
  ColorRGBAf(GLclampf red = 0, GLclampf green = 0, GLclampf blue = 0, GLclampf alpha = 1)
  {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
  }
  void setColor(GLclampf red = 0, GLclampf green = 0, GLclampf blue = 0, GLclampf alpha = 1)
  {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
  }
};

struct Rect
{
  int x, y, z, width, height, depth;
  Rect(int x = 0,int y = 0, int w =0, int h=0)
  {
    setRect(x,y,0,w,h,0);
  }

  Rect(int x = 0,int y = 0, int z = 0, int w =0, int h=0, int d = 0)
  {
    setRect(x,y,z,w,h,d);
  }

  void setRect(int x = 0,int y = 0, int z = 0, int w =0, int h=0, int d = 0)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = w;
    this->height = h;
    this->depth = d;
  }


};

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


class Utils
{  
  Utils(){}
public:
  static bool loadPngImage(const char *name, float &outWidth, float &outHeight, bool &outHasAlpha, GLubyte **outData);
};

#endif // UTILS_H
