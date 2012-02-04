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

#include "utils.h"
#include <png.h>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

bool Utils::loadPngImage(const char *name, float &outWidth, float &outHeight, bool &outHasAlpha, GLubyte **outData)
{
    png_structp png_ptr;
    png_infop info_ptr;
    unsigned int sig_read = 0;
    //int color_type, interlace_type;
    FILE *fp;

    if ((fp = fopen(name, "rb")) == NULL)
        return false;

    /* Create and initialize the png_struct
     * with the desired error handler
     * functions.  If you want to use the
     * default stderr and longjump method,
     * you can supply NULL for the last
     * three parameters.  We also supply the
     * the compiler header file version, so
     * that we know if the application
     * was compiled with a compatible version
     * of the library.  REQUIRED
     */
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
            NULL, NULL, NULL);

    if (png_ptr == NULL) {
        fclose(fp);
        return false;
    }

    /* Allocate/initialize the memory
     * for image information.  REQUIRED. */
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        fclose(fp);
        png_destroy_read_struct(&png_ptr, png_infopp_NULL, png_infopp_NULL);
        return false;
    }

    /* Set error handling if you are
     * using the setjmp/longjmp method
     * (this is the normal method of
     * doing things with libpng).
     * REQUIRED unless you  set up
     * your own error handlers in
     * the png_create_read_struct()
     * earlieb.
     */
    if (setjmp(png_jmpbuf(png_ptr))) {
        /* Free all of the memory associated
         * with the png_ptr and info_ptr */
        png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);
        fclose(fp);
        /* If we get here, we had a
         * problem reading the file */
        return false;
    }

    /* Set up the output control if
     * you are using standard C streams */
    png_init_io(png_ptr, fp);

    /* If we have already
     * read some of the signature */
    png_set_sig_bytes(png_ptr, sig_read);

    /*
     * If you have enough memory to read
     * in the entire image at once, and
     * you need to specify only
     * transforms that can be controlled
     * with one of the PNG_TRANSFORM_*
     * bits (this presently excludes
     * dithering, filling, setting
     * background, and doing gamma
     * adjustment), then you can read the
     * entire image (including pixels)
     * into the info structure with this
     * call
     *
     * PNG_TRANSFORM_STRIP_16 |
     * PNG_TRANSFORM_PACKING  forces 8 bit
     * PNG_TRANSFORM_EXPAND forces to
     *  expand a palette into RGB
     */
    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16 | PNG_TRANSFORM_PACKING | PNG_TRANSFORM_EXPAND, png_voidp_NULL);

    outWidth = (float)info_ptr->width;
    outHeight = (float)info_ptr->height;
    switch (info_ptr->color_type) {
        case PNG_COLOR_TYPE_RGBA:
            outHasAlpha = true;
            break;
        case PNG_COLOR_TYPE_RGB:
            outHasAlpha = false;
            break;
        default:
            std::cout << "Color type " << info_ptr->color_type << " not supported" << std::endl;
            png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
            fclose(fp);
            return false;
    }
    unsigned int row_bytes = png_get_rowbytes(png_ptr, info_ptr);
    *outData = (unsigned char*) malloc(row_bytes * outHeight);

    png_bytepp row_pointers = png_get_rows(png_ptr, info_ptr);

    for (int i = 0; i < outHeight; i++) {
        // note that png is ordered top to
        // bottom, but OpenGL expect it bottom to top
        // so the order or swapped
        memcpy(*outData+(row_bytes * ((int)outHeight-1-i)), row_pointers[i], row_bytes);
    }

    /* Clean up after the read,
     * and free any memory allocated */
    png_destroy_read_struct(&png_ptr, &info_ptr, png_infopp_NULL);

    /* Close the file */
    fclose(fp);

    /* That's it */
    return true;
}

float Utils::getDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

void Utils::hsv2rgb(float h, float s, float v, float &outR, float &outG, float &outB)
{
  int var_i;
  float var_1,var_2, var_3,var_h;

  if ( s == 0 ) //HSV from 0 to 1
  {
    outR = outG = outB = v;
    return;
  }
  else
  {
    var_h = h * 6;
    if ( var_h == 6 )
      var_h = 0;      //H must be < 1

    var_i = floor( var_h );             //Or ... var_i = floor( var_h )
    var_1 = v * ( 1 - s );
    var_2 = v * ( 1 - s * ( var_h - var_i ) );
    var_3 = v * ( 1 - s * ( 1 - ( var_h - var_i ) ) );

    switch (var_i)
    {
    case 0:
      outR = v;
      outG = var_3;
      outB = var_1;
      break;
    case 1:
      outR = var_2;
      outG = v;
      outB = var_1;
      break;
    case 2:
      outR = var_1;
      outG = v;
      outB = var_3;
      break;
    case 3:
      outR = var_1;
      outG = var_2;
      outB = v;
      break;
    case 4:
      outR = var_3;
      outG = var_1;
      outB = v;
      break;
    case 5:
      outR = v;
      outG = var_1;
      outB = var_2;
      break;
    }
  }
}

MyVertex::MyVertex()
{
  setParams(0,0,0,0,0,0,0,0);
}

MyVertex::MyVertex(float x, float y, float z, float tx, float ty)
{
  setParams(x,y,z,tx,ty,x,y,z);
}

void MyVertex::setParams(float x, float y, float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

void MyVertex::setParams(float x, float y, float z, float tx, float ty)
{
  setParams(x,y,z);
  this->tx = tx;
  this->ty = ty;
}

void MyVertex::setParams(float x, float y, float z, float tx, float ty, float nx, float ny, float nz)
{
  setParams(x,y,z,tx,ty);
  this->nx = nx;
  this->ny = ny;
  this->nz = nz;
}

void MyVertex::makeTexturePoints(float w, float h, CoordMapType xmap, CoordMapType ymap)
{
  float xval = 0, yval = 0;
  switch(xmap)
  {
  case MAP_X:
    xval = x;
    break;
  case MAP_Y:
    xval = y;
    break;
  case MAP_Z:
    xval = z;
    break;
  }

  switch(ymap)
  {
  case MAP_X:
    yval = x;
    break;
  case MAP_Y:
    yval = y;
    break;
  case MAP_Z:
    yval = z;
    break;
  }

  if(w!=0)
    this->tx = xval/w;
  if(h!=0)
    this->ty = 1-yval/h;
}

void MyVertex::makeNormals(float xoffset, float yoffset, float zoffset)
{
  nx = x+xoffset;
  ny = y+yoffset;
  nz = z+zoffset;
}

bool Collisions::rect2sphere(Block b, float x, float y, float z, float radius)
{
  float closestX, closestY, closestZ;
  if(x < b.x)
  {
    closestX = b.x;
  }
  else if(x > b.x + b.width)
  {
    closestX = b.x + b.width;
  }
  else
  {
    closestX = x;
  }

  if(y < b.y)
  {
    closestY = b.y;
  }
  else if(y > b.y + b.height)
  {
    closestY = b.y + b.height;
  }
  else
  {
    closestY = y;
  }

  if(z < b.z)
  {
    closestZ = b.z;
  }
  else if(z > b.z + b.depth)
  {
    closestZ = b.z + b.depth;
  }
  else
  {
    closestZ = z;
  }

  float distance = Utils::getDistance(closestX, closestY, closestZ, x, y, z);

  if(distance<radius)
  {
    return true;
  }
  return false;
}

bool Collisions::rect2rect(Block r1, Block r2)
{
  return false;
}
