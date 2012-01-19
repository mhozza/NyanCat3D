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
#include "gameroom.h"

#include <GL/glut.h>
#include <iostream>
using namespace std;


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
  glDepthMask(GL_TRUE);
  //glEnable(GL_CULL_FACE);

  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  //textures
  setupTextures();
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glEnable(GL_TEXTURE_2D);

}

int Game::start(int argc = 0, char *argv[] = NULL)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowPosition(50, 50);
  glutInitWindowSize(WINDOW_W, WINDOW_H);

  glutCreateWindow("NyanCat 3D");

  init();

  // Zaregistrujeme callback funkcie
  glutDisplayFunc(Renderer::renderWrapper);
  glutIdleFunc(Renderer::renderWrapper);
  glutReshapeFunc(Renderer::reshapeWrapper);
  glutTimerFunc(30, Renderer::timerWrapper, 30);
  glutMouseFunc(Mouse::mouseFuncWrapper);
  glutKeyboardFunc(Keyboard::keyboardFuncWrapper);
  glutSpecialFunc(Keyboard::keyboardSpecialFuncWrapper);


  renderer->setRoom(new MenuRoom(this,WINDOW_W,WINDOW_H));
  //renderer->setRoom(new GameRoom());
  glutMainLoop();
  return 0;
}

bool Game::setupTextures()
{
  const char * texFiles[] = {"graphics/stars.png"};

  glGenTextures(TEXTURES_NUM,texId);
  for(int i = 0;i<TEXTURES_NUM;i++)
  {
    glBindTexture(GL_TEXTURE_2D,texId[i]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    float width, height;
    bool alpha;
    GLubyte * img;
    if(!Utils::loadPngImage(texFiles[i],width,height,alpha,&img))
    {
      cerr << "Unable to load texture: " << texFiles[i] << endl;
      continue;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, alpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, img);
  }

  return true;
}

GLuint Game::getTextureId(int index)
{
  return texId[index];
}
