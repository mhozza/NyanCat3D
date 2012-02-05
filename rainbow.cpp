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

#include "rainbow.h"
#include <iostream>

Rainbow::Rainbow(GameObject* player, float speed, int maxlife)
{
  this->player = player;
  this->speed = speed;
  this->maxlife = maxlife;
}

void Rainbow::draw()
{
  glTranslatef(0,0.114,-0.188);
  glScalef(0.1,2,-2);

  glDisable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE);
  glDisable(GL_LIGHTING);
  glPointSize(6);

  glBegin(GL_POINTS);
  for(unsigned i = 0;i<particleSystem.size();i++)
  {
    glColor4f(particleSystem[i].r,particleSystem[i].g,particleSystem[i].b,particleSystem[i].life/maxlife);
    glVertex3f(particleSystem[i].x,particleSystem[i].y,particleSystem[i].z);
  }
  glEnd();

  glEnable(GL_LIGHTING);
  glDisable(GL_BLEND);
  glEnable(GL_TEXTURE_2D);
}

void Rainbow::updateParticleSystem()
{
  //create new
  for(float x = -1; x<1; x+=0.2)
  {
    for(float y = 0; y<0.228; y+=0.02)
    {
      for(float z = 0;z>speed;z-=0.01)
      {
        Particle p;
        p.x = x;
        p.y = -y+player->getY()/2;
        p.z = z;
        p.life = maxlife;
        p.vz = speed;
        Utils::hsv2rgb(y/0.228,1,1,p.r,p.g,p.b);
        particleSystem.push_back(p);
      }
    }
  }
  //update all
  unsigned i = 0;
  while(i<particleSystem.size())
  {
    if((particleSystem[i].life--)<=0)
    {
      if(i<particleSystem.size())
      {
        particleSystem[i] = particleSystem.back();
      }
      particleSystem.pop_back();
    }
    else
    {
      //vx, vy == 0
      //particleSystem[i].x+=particleSystem.vx;
      //particleSystem[i].y+=particleSystem.vy;
      particleSystem[i].z+=particleSystem[i].vz;
      i++;
    }
  }
}

void Rainbow::step()
{
  this->setX(player->getX());
  //this->setY(player->getY());
  this->setZ(player->getZ());
  updateParticleSystem();
}
