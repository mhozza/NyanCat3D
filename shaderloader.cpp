/*
 *    Copyright (C) 2012  Michal Hozza (mhozza@gmail.com)
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

#include "shaderloader.h"

ShaderLoader::ShaderLoader(string vertexShaderFileName, string fragmentShaderFileName)
{
  GLuint vertexShader, fragmentShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  int fd = open(vertexShaderFileName.c_str(), O_RDONLY, 0);
  if (fd == -1) {
    perror("Error opening file");
    return;
  }

  struct stat sb;
  fstat(fd,&sb);

  char* sh = (char*)mmap(0,sb.st_size,PROT_READ,MAP_SHARED,fd,0);
  if (sh == MAP_FAILED) {
     close(fd);
     perror("Error mmapping the file");
     return;
  }
  glShaderSource(vertexShader, 1, (const GLchar**)&sh, (const GLint*)&sb.st_size);
  if (munmap(sh, sb.st_size) == -1) {
     perror("Error un-mmapping the file");
  }
  close(fd);
  glCompileShader(vertexShader);
  GLint result;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
  if(!result)
  {
    perror("Error in compiling shader");
  }

  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  fd = open(fragmentShaderFileName.c_str(), O_RDONLY, 0);
  if (fd == -1) {
    perror("Error opening file");
    return;
  }
  fstat(fd,&sb);
  sh = (char*)mmap(0,sb.st_size,PROT_READ,MAP_SHARED,fd,0);
  if (sh == MAP_FAILED) {
     close(fd);
     perror("Error mmapping the file");
     return;
  }
  glShaderSource(fragmentShader, 1, (const GLchar**)&sh, (const GLint*)&sb.st_size);
  if (munmap(sh, sb.st_size) == -1) {
     perror("Error un-mmapping the file");
  }
  close(fd);
  glCompileShader(fragmentShader);
  GLint result;
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
  if(!result)
  {
    perror("Error in compiling shader");
  }

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram,vertexShader);
  glAttachShader(shaderProgram,fragmentShader);
  glLinkProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

GLuint ShaderLoader::getProgram()
{
  return shaderProgram;
}

ShaderLoader::~ShaderLoader()
{
  glDeleteProgram(shaderProgram);
}
