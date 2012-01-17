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

#include "game.h"
#include "menuroom.h"

#include <GL/glut.h>

Game::Game()
{
  this->renderer = Renderer::getInstance();
}

Game::~Game()
{
  delete renderer;
}

void Game::init()
{
  glShadeModel(GL_SMOOTH);
  glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

int Game::start(int argc = 0, char *argv[] = NULL)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowPosition(50, 50);
  glutInitWindowSize(800, 600);
  glutCreateWindow("NyanCat 3D" );

  init();

  // Zaregistrujeme callback funkcie
  glutDisplayFunc(Renderer::renderWrapper);
  glutReshapeFunc(Renderer::reshapeWrapper);
  /*glutKeyboardFunc(keyboard);
  glutSpecialFunc(special_keys);*/

  renderer->setRoom(new MenuRoom());
  glutMainLoop();
  return 0;
}
