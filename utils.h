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

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

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

struct Point
{
  float x,y,z;
  Point():x(0),y(0),z(0){}
  Point(float x, float y, float z) :x(x),y(y),z(z) {}
};

struct Block
{
  float x, y, z, width, height, depth;
  Block(float x = 0,float y = 0, float w =0, float h=0)
  {
    setRect(x,y,0,w,h,0);
  }

  Block(float x = 0,float y = 0, float z = 0, float w =0, float h=0, float d = 0)
  {
    setRect(x,y,z,w,h,d);
  }

  void setRect(float x = 0,float y = 0, float z = 0, float w =0, float h=0, float d = 0)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = w;
    this->height = h;
    this->depth = d;
  }

  Block operator+(Point p)
  {
    return Block(*this)+=p;
  }
  Block operator+=(Point p)
  {
    this->x+=p.x;
    this->y+=p.y;
    this->z+=p.z;
    return *this;
  }
};

enum CoordMapType {MAP_X,MAP_Y,MAP_Z};

struct MyVertex
{
  float x,y,z;
  float tx,ty;
  float nx, ny, nz;
  //float padding[3];
  MyVertex();
  MyVertex(float x, float y, float z, float tx, float ty);
  void setParams(float x, float y, float z);
  void setParams(float x, float y, float z, float tx, float ty);
  void setParams(float x, float y, float z, float tx, float ty, float nx, float ny, float nz);
  void makeTexturePoints(float w, float h, CoordMapType xmap, CoordMapType ymap);
  void makeNormals(float xoffset = 0, float yoffset = 0, float zoffset = 0);
};

struct Particle
{
  float x, y, z;
  float vx, vy, vz;
  float r, g, b;
  float life;
};

class Utils
{  
  Utils(){}
public:
  static int sgn(float v);
  static bool loadPngImage(const char *name, float &outWidth, float &outHeight, bool &outHasAlpha, GLubyte **outData);
  static float getDistance(float x1, float y1, float z1, float x2, float y2, float z2);
  static void hsv2rgb(float h, float s, float v, float &outR, float &outG, float &outB);    
};

class Collisions
{
  static Point closest(Block b, float x, float y, float z);
  static Point closest(Block b, Point p);

public:
  static bool block2sphere(Block b, float x, float y, float z, float radius);
  static bool block2block(Block b1, Block b2);
};

#endif // UTILS_H
