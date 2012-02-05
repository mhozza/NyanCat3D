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

#ifndef LEVELSELECTBUTTON_H
#define LEVELSELECTBUTTON_H

#include "selectbutton.h"

enum Level {easy,medium,difficult};

class LevelSelectButton : public SelectButton
{
  Level level;
public:
  LevelSelectButton(SelectGroup * parent, int x, int y, Level l);
};

#endif // LEVELSELECTBUTTON_H
