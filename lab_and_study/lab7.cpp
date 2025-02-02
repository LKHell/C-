/*
    201403-Added by Dr. Yawei Liang:
    To run this program:
    1. create a c++ console application program, and add an existing item: tutorial04.cpp and math_3d.h
    2. in project property: linker - input - additional dependencies, add: glew32.lib and freeglut.lib
    3. build solution and run
	(not work for MSVS2010, but good for MSVS2013)

	Copyright 2010 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Tutorial 04 - shaders
*/

#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include <stdio.h>
#include "math_3d.h"

#include<iostream>// generate message
using std::cout;   // dot.cpp needs this

#define _USE_MATH_DEFINES // for C++
#include<math.h>

int w=1024;  // the size of the screen space, top-right: 1024, 768
int h=768;   // bottom-left: 0, 0


GLuint VBO;

//Position include Position.x,Position.y,Position.z 
// 330 means glsl 3.3
static const char* pVS = "														\n\
#version 330																	\n\
																				\n\
layout (location = 0) in vec3 Position;											\n\
out vec4 Color;																	\n\
void main()																		\n\
{																				\n\
    gl_Position = vec4(0.6 * Position.x, 0.6 * Position.y,0.6 *  Position.z, 1.0);	\n\
	Color = vec4(clamp(Position.x, 0.0, 1.0),0.0,clamp(Position.z, 0.5, 1.0),1.0);								\n\
}";

static const char* pFS = "                                                          \n\
#version 330                                                                        \n\
                                                                                    \n\
in vec4 Color;                                                                      \n\
                                                                                    \n\
out vec4 FragColor;                                                                 \n\
                                                                                    \n\
void main()                                                                         \n\
{                                                                                   \n\
    FragColor = Color;                                                          \n\
}";

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}


static void InitializeGlutCallbacks()
{
	cout<<"Yawei, the OpenGL version is: "<<glGetString(GL_VERSION) <<"\n";
	cout<<glGetString(GL_VENDOR) <<"\n";

    glutDisplayFunc(RenderSceneCB);
}

static void CreateVertexBuffer()  //set 3 vector
{
    Vector3f Vertices[3];   
    Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

 	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
    GLuint ShaderObj = glCreateShader(ShaderType);   //create shaderobj

    if (ShaderObj == 0) {
        fprintf(stderr, "Error creating shader type %d\n", ShaderType);
        exit(0);
    }

    const GLchar* p[1];
    p[0] = pShaderText;
    GLint Lengths[1];
    Lengths[0]= strlen(pShaderText);
    glShaderSource(ShaderObj, 1, p, Lengths);//specify source code
    
	glCompileShader(ShaderObj); //compiling 
    
	GLint success;
    glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];
        glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
        exit(1);
    }

    glAttachShader(ShaderProgram, ShaderObj); //attach compiled shaderobj
}

static void CompileShaders()
{
    GLuint ShaderProgram = glCreateProgram();

    if (ShaderProgram == 0) {
        fprintf(stderr, "Error creating shader program\n");
        exit(1);
    }

    AddShader(ShaderProgram, pVS, GL_VERTEX_SHADER);
    AddShader(ShaderProgram, pFS, GL_FRAGMENT_SHADER);

    GLint Success = 0;
    GLchar ErrorLog[1024] = { 0 };

    glLinkProgram(ShaderProgram);
    glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
        exit(1);
	}

    glValidateProgram(ShaderProgram);  //check
    glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
    if (!Success) {
        glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
        fprintf(stderr, "Invalid shader program: '%s'\n", ErrorLog);
        exit(1);
    }

    glUseProgram(ShaderProgram); //completed, linked shader program you set it into the pipeline state using the call above
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("LK's lab7 triangle");

    InitializeGlutCallbacks();

    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      return 1;
    }
    
    printf("GL version: %s\n", glGetString(GL_VERSION));

	glClearColor(0.0f, 0.505f, 0.502f, 0.0f);      //set background teal #008080

    CreateVertexBuffer();

    CompileShaders();

    glutMainLoop();

    return 0;
}