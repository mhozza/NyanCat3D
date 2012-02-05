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

#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "mouse.h"
#include "keyboard.h"

#define TEXTURES_NUM 4

enum Level {easy,medium,difficult};

class Renderer;

class Game
{
    bool run;
    void init();
    GLuint texId[TEXTURES_NUM];
    Renderer* renderer;
    bool setupTextures();
    static float speed;
public:
    Game();
    ~Game();
    int start(int argc, char *argv[]);
    GLuint getTextureId(int index);
    static void setLevel(Level l);
    static bool fog;
    static float getSpeed(){return Game::speed;}
};


#endif // GAME_H
