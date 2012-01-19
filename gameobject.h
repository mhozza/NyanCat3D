/*
 *    Copyright (C) 2011-2011  Michal Hozza (mhozza@gmail.com)
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

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "model.h"
#include <cstddef>

class GameObject
{
protected:
    float x,y,z,width, height, depth;
    float speedX,speedY,speedZ;
    Model* model;
    GameObject(){model = NULL; speedX = 0; speedY = 0; speedZ = 0;}
public:    
    GameObject(Model * model,float x, float y, float z);
    ~GameObject();
    virtual void move();
    inline float getX(){return x;}
    inline float getY(){return y;}
    inline float getZ(){return z;}
    inline void setX(float x){this->x = x;}
    inline void setY(float y){this->y = y;}
    inline void setZ(float z){this->z = z;}
    Model* getModel();
    void setModel(Model* model);
    virtual void action(int){} // param: actionID
    virtual void step(){}
};

#endif // GAMEOBJECT_H
