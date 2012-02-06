#ifndef __SHADER_H
#define __SHADER_H

#include <string>

#if ( (defined(__MACH__)) && (defined(__APPLE__)) )   
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#else
#include <stdlib.h>
#define GL_GLEXT_PROTOTYPES
//#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#endif

class Shader {
  unsigned int shader_id;
  unsigned int shader_vp;
  unsigned int shader_fp;
public:
	Shader();
	Shader(const char *vsFile, const char *fsFile);
	~Shader();
	
    void init(const char *vsFile, const char *fsFile);
    
	void bind();
	void unbind();
	
    unsigned int id();
};

#endif
