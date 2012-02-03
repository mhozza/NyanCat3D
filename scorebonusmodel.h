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

#ifndef SCOREBONUSMODEL_H
#define SCOREBONUSMODEL_H

#define GL_GLEXT_PROTOTYPES
#include "GL/gl.h"
#include "GL/glext.h"
#include "model.h"


class ScoreBonusModel : public Model
{
  GLuint VertexVBOID, IndexVBOID;
  GLuint indexSize;
public:
    ScoreBonusModel(int textureid);
    ~ScoreBonusModel();
    void draw();
};

#endif // SCOREBONUSMODEL_H

