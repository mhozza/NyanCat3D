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

bool Game::fog = true;
bool Game::paused = false;
float Game::speed = 0.2;



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
  glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);         // Really Nice Point Smoothing

  //textures
  setupTextures();
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glEnable(GL_TEXTURE_2D);

  //fog
  //glEnable(GL_FOG);
  glFogf(GL_FOG_MODE,GL_EXP2);
  glFogf(GL_FOG_DENSITY,0.047);
  glHint(GL_FOG_HINT, GL_NICEST);

  /*glFogf(GL_FOG_START,0);
  glFogf(GL_FOG_END,1);*/
  //glFogf(GL_FOG_COLOR,);

  //light

  float LightPos[4]={1.0f,1.0f,1.f,0.0f};
  float Ambient[4]={0.2,0.2,0.2,1};
  GLfloat Diffuse[] = { 1, 1, 1, 1 };
  GLfloat Specular[] = { 1, 1, 1, 1 };

  float LightPos2[4]={0.0f,0.0f,-2.0f,1.0f};
  float Ambient2[4]={0.2,0.2,0.2,1};
  GLfloat Diffuse2[] = { 1, 1, 1, 1 };
  GLfloat Specular2[] = { 1, 1, 1, 1 };


  glEnable(GL_LIGHTING);

  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0,GL_POSITION,LightPos);
  glLightfv(GL_LIGHT0,GL_AMBIENT,Ambient);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,Diffuse);
  glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);

  glEnable(GL_LIGHT1);
  glLightfv(GL_LIGHT1,GL_POSITION,LightPos2);
  glLightfv(GL_LIGHT1,GL_AMBIENT,Ambient2);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,Diffuse2);
  glLightfv(GL_LIGHT1,GL_SPECULAR,Specular2);

  /*glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
  glEnable(GL_COLOR_MATERIAL);*/


}

int Game::start(int argc = 0, char *argv[] = NULL)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

  //glutInitWindowPosition(, 50);
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
  glutPassiveMotionFunc(Mouse::motionFuncWrapper);


  renderer->setRoom(new MenuRoom(this,WINDOW_W,WINDOW_H));
  //renderer->setRoom(new GameRoom());
  glutMainLoop();
  return 0;
}

bool Game::setupTextures()
{
  const char * texFiles[] = {"graphics/stars.png", "graphics/noise.png",
                             "graphics/nyancat.png", "graphics/score.png",
                             "graphics/spiral.png"};

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

void Game::setLevel(Level l)
{
  switch(l)
  {
  case easy:
    Game::speed = 0.2;
    break;
  case medium:
    Game::speed = 0.3;
    break;
  case difficult:
    Game::speed = 0.4;
    break;
  }
}
