/*
LiKunhao
*/



/*
// File:        LKHao_home.c
// Author:      Li Kunhao
// Created:     27/12/2016
// Project:     Home
// Description: (H) house  - A house should be created and displayed.
(T) tree- At least one tree should be created and displayed.
(S) Sun C the sun is a must object.
(E) extra environment object(s) - you can create any other extra object on the piece of land you have.
(V) viewpoints - your program should enable viewer to view your home with different angles.
//
// Controls:    Left Arrow  - Rotate Left
//              Right Arrow - Rotate Right
//              Up Arrow    - Rotate Up
//              Down Arrow  - Rotate Down
*/
// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------

#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include <iostream>
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

GLfloat w = 900;  // the size of the screen space, top-right: 800, 600
GLfloat h = 900;  // bottom-left: 0, 0




// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------


GLfloat s = 30.0;  //global scalef
void set_display() {
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	
	glScalef(s, s, s);
	glTranslated(0, 0, 4.0);
}

void set_display_ground() {
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	//glTranslated(0, 0, 30);
	glScalef(s, s, s);
}


void make_GL_QUAD_STRIP(GLfloat a, GLfloat b, GLfloat c)
{
	glBegin(GL_QUAD_STRIP);
	glColor3f(a, b, c);
	glVertex3f(1, 0.0, -1);      // P1
	glVertex3f(1, 1, -1);      // P2 
	glVertex3f(-1, 0.0, -1);      // P3
	glVertex3f(-1, 1, -1);      // P4								
	glVertex3f(-1, 0.0, 1);//p5
	glVertex3f(-1, 1, 1);//p6
	glVertex3f(1, 0.0, 1);//p7
	glVertex3f(1, 1, 1);//p8
	//glVertex3f(1, 0.0, -1);      // P9
	//glVertex3f(1, 1, -1);			//p10
	glEnd();
	glBegin(GL_QUAD_STRIP);
	glColor3f(a, b, c);
	glVertex3f(-1, 0, 1);
	glVertex3f(-1, 0, -1);
	glVertex3f(1, 0, 1);
	glVertex3f(1, 0, -1);
	glVertex3f(1, 1, 1);
	glVertex3f(1, 1, -1);
	glVertex3f(-1, 1, 1);
	glVertex3f(-1, 1, -1);
	glEnd();

}

void make_GL_QUADS(GLfloat a, GLfloat b, GLfloat c)//bot
{
	glBegin(GL_QUADS);
	glColor3f(a, b, c);
	glVertex3f(1, 0.0, -1);      // P1
	glVertex3f(1, 0.0, 1);      // P2 
	glVertex3f(-1, 0.0, 1);      // P3
	glVertex3f(-1, 0.0, -1);      // P4		
	glEnd();
}


void make_GL_QUADS_front(GLfloat a, GLfloat b, GLfloat c)
{
	glBegin(GL_QUADS);
	glColor3f(a, b, c);

	glVertex3f(1.0, 0.0, 0.0);      // P1
	glVertex3f(1.0, 1.0, 0.0);      // P2 
	glVertex3f(0.0, 1.0, 0.0);      // P3
	glVertex3f(0.0, 0.0, 0.0);      // P4	
	glEnd();
}
void make_GL_QUADS_right(GLfloat a, GLfloat b, GLfloat c)
{
	glBegin(GL_QUADS);
	glColor3f(a, b, c);

	glVertex3f(0.0, 1.0, 0.0);      // P1
	glVertex3f(0.0, 1.0, 1.0);      // P2 
	glVertex3f(0.0, 0.0, 1.0);      // P3
	glVertex3f(0.0, 0.0, 0.0);      // P4	
	glEnd();
}


void make_tree(GLfloat a, GLfloat b)
{
	set_display();
	//glTranslatef(-6, 1.5, 0.0);
	glTranslatef(a, 1.5, b);
	glScalef(1, 1, 1);
	glRotatef(45, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 0);
	glVertex3f(0.0f, 2.0*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd(); //
	glRotatef(45, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 2.0*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd();

	set_display();
	glTranslatef(a, 0.5, b);
	glScalef(1, 1, 1);
	glRotatef(45, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 0);
	glVertex3f(0.0f, 2.0*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd();
	glRotatef(45, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 2.0*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd();



	set_display();
	glTranslatef(a, -0.2, b);
	glScalef(0.3, 1.3, 0.3);
	make_GL_QUAD_STRIP(160 / 255.0, 82 / 255.0, 45 / 255.0);
}
void make_grass(GLfloat a, GLfloat b)
{
	set_display();
	//glTranslatef(-6, 1.5, 0.0);
	glTranslatef(a, 0.2, b);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(45, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(139 / 255.0, 69 / 255.0, 19 / 255.0);
	glVertex3f(0.0f, -0.7*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd(); //
	glTranslatef(0, 0.3, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 0.4);
	glVertex3f(0.0f, -1.0*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd(); 
	//glRotatef(45, 0.0, 1.0, 0.0);
	glTranslatef(0, 0.4, 0);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 1, 0.4);
	glVertex3f(0.0f, -1.0*sin(M_PI / 3), 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd();
}

void display() {
	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	// Reset transformations

	/*---------------6x6----------------*/
	set_display();
	glScalef(3, 3, 3);
	make_GL_QUAD_STRIP(0.118, 0.565, 0.5);

	/*---------------4x2------------------*/

	set_display();

	glScalef(1, 3, 2);
	glTranslatef(4.0, 0.0, 0.5);

	make_GL_QUAD_STRIP(1, 0.5, 0.800);

	/*-------------2x2---------------------*/



	set_display();
	glScalef(1, 0.5, 1);
	glTranslatef(4.0, -0.1, -2.0);
	make_GL_QUAD_STRIP(1.0, 1.0, 1.0);


	glTranslatef(0.0, 1.01, 0.0);
	make_GL_QUADS(0.5, 1.0, 1.0);


	/*--------------bottom------------------*/


	set_display();
	glScalef(4.1, 0.2, 3.1);
	glTranslatef(0.25, 0.0, 0.0);
	make_GL_QUAD_STRIP(1.0, 0.5, 1.0);
	/*glTranslatef(0.0, 1.0, 0.0);
	make_GL_QUADS(0.5, 1.0, 0.3);*/



	/*--------------------top---------------*/

	set_display();

	glScalef(4.1, 3, 3.1);
	glTranslatef(0.25, 1.0, 0.0);
	glRotatef(45, 0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN); // construct a pyramid
	glColor3f(0.4f, 0.5f, 0.5f);    // yellow vertex at the peak
	glVertex3f(0.0f, 0.7*sin(M_PI / 3), 0.0f);
	// orange vextex
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.5f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glEnd(); //


	/*--------------------pillar---------------*/

	set_display();
	glTranslatef(4.9, 0.0, -2.9);
	glScalef(0.15, 3, 0.15);
	make_GL_QUAD_STRIP(1.0, 1.0, 1.0);


	/*--------------------door---------------*/


	set_display();
	glTranslatef(3.25, 0.0, -1.1);
	glScalef(1.5, 2.5, 0.15);
	//make_GL_QUAD_STRIP(0, 0, 1);
	make_GL_QUADS_front(0, 0, 1);

	/*----------door_Vertical--------------*/
	set_display();
	glTranslatef(3.7, 0.0, -1.11);
	glScalef(0.13, 2.6, 1.0);
	make_GL_QUADS_front(1.0, 1.0, 1.0);
	/*----------door_Horizontal-----------------*/
	set_display();
	glTranslatef(3.2, 2.0, -1.11);
	glScalef(1.5, 0.13, 1.0);
	make_GL_QUADS_front(1, 1.0, 1);
	/*-----------door_handle------------------------*/
	set_display();
	glTranslatef(4.0, 1.2, -1.11);
	glScalef(0.1, 0.2, 1.0);
	make_GL_QUADS_front(1, 0, 1);

	//frame
	set_display();
	glTranslatef(3.25, 0.0, -1.1);
	glScalef(0.1, 5, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 1, 1.0);
	set_display();
	glTranslatef(4.7, 0.0, -1.1);
	glScalef(0.1, 5, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 1, 1.0);
	set_display();
	glTranslatef(4.0, 2.5, -1.1);
	glScalef(1.75, 0.3, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 1, 1.0);


	/*-------------window_front--------------------*/

	set_display();
	glTranslatef(-2.0, 0.5, -3.01);
	glScalef(3.5, 2.0, 1.0);
	make_GL_QUADS_front(1, 1.0, 0.5);

	//left
	set_display();
	glTranslatef(-1.5, 0.5, -3.02);
	glScalef(0.2, 2.0, 1.0);
	make_GL_QUADS_front(1, 0.5, 1.0);
	//right
	set_display();
	glTranslatef(0.7, 0.5, -3.02);
	glScalef(0.2, 2.0, 1.0);
	make_GL_QUADS_front(1, 0.5, 1.0);
	//bot
	set_display();
	glTranslatef(-2.0, 0.8, -3.02);
	glScalef(3.5, 0.2, 1.0);
	make_GL_QUADS_front(1, 0.5, 1.0);

	//frame_left
	set_display();
	glTranslatef(-2.0, 0.5, -3.01);
	glScalef(0.1, 4.0, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);
	//frame_right
	set_display();
	glTranslatef(1.5, 0.5, -3.01);
	glScalef(0.1, 4.0, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);
	//frame_bot
	set_display();
	glTranslatef(-0.25, 0.5, -3.01);
	glScalef(3.5, 0.2, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);
	//frame_top
	set_display();
	glTranslatef(-0.25, 2.5, -3.01);
	glScalef(3.8, 0.4, 0.4);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);


	/*---------------window_right----------------*/
	set_display();
	glTranslatef(5.01, 0.7, 0.0);
	glScalef(1.0, 1.8, 2.0);
	make_GL_QUADS_right(1, 1.0, 0.5);

	//mid
	set_display();
	glTranslatef(5.02, 1.0, 0.95);
	glScalef(1.0, 1.5, 0.1);
	make_GL_QUADS_right(1, 0.5, 0.0);

	//bot
	set_display();
	glTranslatef(5.02, 1.0, 0.0);
	glScalef(1.0, 0.2, 2.0);
	make_GL_QUADS_right(1, 0.5, 0.0);
	//frame_left
	set_display();
	glTranslatef(5.02, 0.6, 0.0);
	glScalef(0.1, 4.0, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);
	//frame_right
	set_display();
	glTranslatef(5.02, 0.6, 2);
	glScalef(0.1, 4.0, 0.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);
	//frame_bot
	set_display();
	glTranslatef(5.02, 0.6, 1.0);
	glScalef(0.2, 0.2, 2);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);
	//frame_top
	set_display();
	glTranslatef(5.02, 2.5, 1.0);
	glScalef(0.4, 0.3, 2.1);
	glScalef(0.5, 0.5, 0.5);
	make_GL_QUAD_STRIP(1.0, 0, 1.0);



	/*-----------------grass_ground---------------*/
	set_display_ground();
	glTranslatef(0, -0.4, 3.0);
	glScalef(12, 0.4, 8);
	make_GL_QUAD_STRIP(0.5, 1, 0.5);


	/*-----------------road---------------*/
	set_display_ground();
	glTranslatef(0, -0.4, -9);
	glScalef(16, 0.4, 4);
	make_GL_QUAD_STRIP(0.5, 0.5, 0.5);

	/*-----------------road_mid---------------*/
	set_display_ground();
	glTranslatef(0, -0.39, -8.7);
	glScalef(16, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	set_display_ground();
	glTranslatef(0, -0.39, -9.3);
	glScalef(16, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);

	set_display_ground();
	glTranslatef(0, -0.39, -6.9);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	set_display_ground();
	glTranslatef(7, -0.39, -6.9);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);

	set_display_ground();
	glTranslatef(14, -0.39, -6.9);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	set_display_ground();
	glTranslatef(-7, -0.39, -6.9);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);

	set_display_ground();
	glTranslatef(-14, -0.39, -6.9);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	//
	set_display_ground();
	glTranslatef(0, -0.39, -11.2);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	set_display_ground();
	glTranslatef(7, -0.39, -11.2);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);

	set_display_ground();
	glTranslatef(14, -0.39, -11.2);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	set_display_ground();
	glTranslatef(-7, -0.39, -11.2);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);

	set_display_ground();
	glTranslatef(-14, -0.39, -11.2);
	glScalef(2, 0.4, 0.15);
	make_GL_QUAD_STRIP(1, 1, 1);
	/*-------------door_to_road---------------*/
	set_display_ground();
	glTranslatef(4, -0.39, -1.0);
	glScalef(1, 0.4, 4);
	make_GL_QUAD_STRIP(0.855, 0.647, 0.125);

	/*-------------tree-----------------*/
	make_tree(-6, 3);
	make_tree(7, 2);
	make_tree(-7, -3);
	/*-------------make_grass-------------------*/
	make_grass(-8, -8);
	make_grass(-5, -8);
	make_grass(-11, -8);
	make_grass(-2, -8);
	make_grass(1, -8);
	make_grass(7, -8);
	make_grass(10, -8);

	/*-------------sun---------------*/
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glColor3f(1, 0.5, 0);
	glTranslatef(150, 400, 9);
	glutSolidSphere(50.0f, 50, 50);

	/*----------------------------*/
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


void init(void) {
	cout << glGetString(GL_VERSION) << "\n";
	cout << glGetString(GL_VENDOR) << "\n";
	glClearColor(0.0, 0.0, 0.0, 0.0);  // select background color: white

	//glPointSize(7.0); // 70 pixel dot!
	glMatrixMode(GL_PROJECTION); // initialize viewing values
	glLoadIdentity(); //
	glOrtho(-w / 2, w / 2, -h / 3, h * 2 / 3, w /2, -w /2); // specify coordinate system


	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_DEPTH_TEST);

}



// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]) {

	//  Initialize GLUT and process user parameters
	glutInit(&argc, argv);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);

	//  Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Create window
	glutCreateWindow("house:");

	//  Enable Z-buffer depth test
	glEnable(GL_DEPTH_TEST);

	// Callback functions

	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	init();
	//  Pass control to GLUT for events
	glutMainLoop();

	//  Return to OS
	return 0;

}
