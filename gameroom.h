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

#ifndef GAMEROOM_H
#define GAMEROOM_H

#include "nyancat.h"
#include "camera.h"
#include "gameobject.h"
#include "room.h"

#include <vector>


using namespace std;

class GameRoom : public Room
{
    //Camera* camera;
    NyanCat* player;
public:
    void generateBlock();
    GameRoom(Game * parent);
    void timer();
};

#endif // GAMEROOM_H
