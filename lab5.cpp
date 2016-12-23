/*
LiKunhao
*/
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

#include <iostream>


// 
// Controls:    Left Arrow  - Rotate Left
//              Right Arrow - Rotate Right
//              Up Arrow    - Rotate Up
//              Down Arrow  - Rotate Down     

// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------
#include <stdio.h>
#include <stdarg.h>
#define _USE_MATH_DEFINES
#include <math.h>
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y = -10; // Front faces viewer, try a different value, like -10
double rotate_x = -10; // Front faces viewer, try a different value, like -10

using std::cout;   // dot.cpp needs this

GLfloat w = 800;  // the size of the screen space, top-right: 800, 600
GLfloat h = 800;  // bottom-left: 0, 0
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	// Reset transformations
	glLoadIdentity();

	// Other Transformations
	// glTranslatef( 0.1, 0.0, 0.0 );      // Not included
	// glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
	glScalef(0.4, 0.4, 0.4);             // Third: scale the object 50 times bigger


	// Rotate when user changes rotate_x and rotate_y
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	// Other Transformations
	// glScalef( 2.0, 2.0, 0.0 );          // Not included



	glBegin(GL_QUAD_STRIP);
	//Multi-colored side - FRONT
	glColor3f(1.0, 0.0, 0.0);     glVertex3f(0.5, -0.5, -0.5);      // P1
	glColor3f(0.0, 1.0, 0.0);     glVertex3f(0.5, 0.5, -0.5);      // P2 

	glColor3f(1.0, 0.0, 1.0);     glVertex3f(-0.5, -0.5, -0.5);      // P3
	glColor3f(0.0, 0.0, 1.0);     glVertex3f(-0.5, 0.5, -0.5);      // P4

	//// White side - BACK
	glVertex3f(-0.5,-0.5, 0.5);//p5
	glVertex3f(-0.5, 0.5, 0.5);//p6
	glVertex3f( 0.5,-0.5, 0.5);//p7
	glVertex3f( 0.5, 0.5, 0.5);//p8

	glEnd();


	glBegin(GL_QUAD_STRIP);

	// //blue side - top

	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	// //red side - bottom

	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();


	glRotatef(45, 0.0, 1.0, 0.0);

	glBegin(GL_TRIANGLE_FAN); // construct a pyramid
	glColor3f(1.0f, 1.0f, 0.0f);    // yellow vertex at the peak
	glVertex3f(0.0f, 1.0*sin(M_PI / 3) + 0.5, 0.0f);

	glColor3f(1.0f, 0.5f, 0.0f);    // orange vextex
	glVertex3f(1.0f, 0.0f + 0.5, 0.0f);

	glColor3f(1.0f, 0.0f, 0.0f);    // red vextex
	glVertex3f(0.0f, 0.0f + 0.5, -1.0f);

	glColor3f(0.0f, 0.0f, 1.0f);    // blue vertex
	glVertex3f(-1.0f, 0.0f + 0.5, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);    // green vertex
	glVertex3f(0.0f, 0.0f + 0.5, 1.0f);

	glColor3f(1.0f, 0.5f, 0.0f);    // orange vertex
	glVertex3f(1.0f, 0.0f + 0.5, 0.0f);
	glEnd(); //


	glTranslatef(1.5, 0.0,1.0);
	glRotatef(-45, 0.0, 1.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	//Multi-colored side - FRONT
	glColor3f(0.0, 1.0, 0.0);  
	glVertex3f(0.5, -0.5, -0.5);      // P1
    glVertex3f(0.5, 0.5, -0.5);      // P2 
	glVertex3f(-0.5, -0.5, -0.5);      // P3
	glVertex3f(-0.5, 0.5, -0.5);      // P4

	//// White side - BACK
	glColor3f(0.0, 1.0, 1.0); 
	glVertex3f(-0.5, -0.5, 0.5);//p5
	glVertex3f(-0.5, 0.5, 0.5);//p6
	glVertex3f(0.5, -0.5, 0.5);//p7
	glVertex3f(0.5, 0.5, 0.5);//p8

	glEnd();


	glBegin(GL_QUAD_STRIP);

	// //blue side - top

	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	// //red side - bottom

	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();





	glFlush();
	glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys(int key, int x, int y) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;

	//  Request display update
	glutPostRedisplay();

}




// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Create window
	glutCreateWindow("LK's house and cube");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);

	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;

}