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

#include "bitmapmodel.h"
#include "utils.h"
#include <GL/glut.h>
#include <iostream>

GLubyte rasters[24] = {
   0xcc, 0xf5, 0xa0, 0x22, 0x88, 0x33, 0xd0, 0x50, 0xc0, 0xd2,
   0xaf, 0xa4, 0xfc, 0xdd, 0x77, 0x70, 0xc6, 0x4a, 0xa0, 0x10,
   0x5b, 0xc0, 0xff, 0xc8};


BitmapModel::BitmapModel(string fname)
{
  depth = 0;
  img = NULL;
  Utils::loadPngImage(fname.c_str(),width,height,hasAlpha,&img);//TODO skontrolovat return value
}

BitmapModel::~BitmapModel()
{
  if(img!=NULL)
  {
    delete img;
  }
}

void BitmapModel::loadBitmap(string fname)
{
  if(!Utils::loadPngImage(fname.c_str(),width,height,hasAlpha,&img))
  {
    cerr << "Unable to load png" << endl;
  }
}

void BitmapModel::draw()
{
  //if(image==NULL) todo vyhod exception
  glRasterPos2i (0, 0);
  //glBitmap(width,height,0,0,0,0,img);
  //glBitmap (10, 12, 10.0, 10.0, 11.0, 0.0, rasters);
  glDrawPixels(width, height, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, img);
}


