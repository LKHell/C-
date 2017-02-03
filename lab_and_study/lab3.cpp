/* LiKunhao   */

// Part 1: headers
#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

#include<iostream> // for output OpenGL version info
using namespace std;

GLfloat w = 800.0;
GLfloat h = 800.0;

// Part 2: display
void display(void)
{
	float angle = 0;
	float x2, y2, cx, cy, fx, fy;
	int cache = 0;
	float radius = 100.0;

	glClear(GL_COLOR_BUFFER_BIT); // set selected background color by glClearColor() 
	glLineWidth((GLfloat)10.0); // 2 pixels wide 
	glDisable(GL_LINE_SMOOTH);
	// glBegin(GL_LINES); // construct an object 
	// glBegin(GL_LINE_STRIP); 

	/*   1.mid  black  */
	glBegin(GL_LINES);
	glColor3f(0, 0, 0); // select drawing color 
	for (angle = 0; angle < 360; angle += 1) {
		float rad_angle = angle * 3.14 / 180;
		x2 = radius * sin((double)rad_angle) + 400;
		y2 = radius * cos((double)rad_angle) + 500;
		if (cache) {
			glVertex3f(cx, cy, 0.0);
			glVertex3f(x2, y2, 0.0);
		}
		else {
			fx = x2;
			fy = y2;
		}
		cache = 1;
		cx = x2;
		cy = y2;
	}
	glVertex3f(x2, y2, 0.0);
	glVertex3f(fx, fy, 0.0);

	glEnd(); // 

	/*   2. blue  top left  */
	glBegin(GL_LINES);
	cache = 0;
	glColor3f(0.118, 0.565, 1.000); // select drawing color 
	for (angle = 0; angle < 360; angle += 1) {
		float rad_angle = angle * 3.14 / 180;
		x2 = radius * sin((double)rad_angle) + 150;
		y2 = radius * cos((double)rad_angle) + 500;
		if (cache) {
			glVertex3f(cx, cy, 0.0);
			glVertex3f(x2, y2, 0.0);
		}
		else {
			fx = x2;
			fy = y2;
		}
		cache = 1;
		cx = x2;
		cy = y2;
	}
	glVertex3f(x2, y2, 0.0);
	glVertex3f(fx, fy, 0.0);

	glEnd(); // 


	/*   3.  top right red  */
	glBegin(GL_LINES); cache = 0;
	glColor3f(1.0, 0.0, 0.0); // select drawing color 
	for (angle = 0; angle < 360; angle += 1) {
		float rad_angle = angle * 3.14 / 180;
		x2 = radius * sin((double)rad_angle) + 650;
		y2 = radius * cos((double)rad_angle) + 500;
		if (cache) {
			glVertex3f(cx, cy, 0.0);
			glVertex3f(x2, y2, 0.0);
		}
		else {
			fx = x2;
			fy = y2;
		}
		cache = 1;
		cx = x2;
		cy = y2;
	}
	glVertex3f(x2, y2, 0.0);
	glVertex3f(fx, fy, 0.0);

	glEnd(); // 
	
	/*   4.  bot left yellow  */

	glBegin(GL_LINES); cache = 0;
	glColor3f(1.000, 0.843, 0.000); // select drawing color 
	for (angle = 0; angle < 360; angle += 1) {
		float rad_angle = angle * 3.14 / 180;
		x2 = radius * sin((double)rad_angle) + 275;
		y2 = radius * cos((double)rad_angle) + 400;
		if (cache) {
			glVertex3f(cx, cy, 0.0);
			glVertex3f(x2, y2, 0.0);
		}
		else {
			fx = x2;
			fy = y2;
		}
		cache = 1;
		cx = x2;
		cy = y2;
	}
	glVertex3f(x2, y2, 0.0);
	glVertex3f(fx, fy, 0.0);

	glEnd(); // 


	/*   5. bot right green  */
	glBegin(GL_LINES); cache = 0;
	glColor3f(0, 1, 0.0); // select drawing color 
	for (angle = 0; angle < 360; angle += 1) {
		float rad_angle = angle * 3.14 / 180;
		x2 = radius * sin((double)rad_angle) + 525;
		y2 = radius * cos((double)rad_angle) + 400;
		if (cache) {
			glVertex3f(cx, cy, 0.0);
			glVertex3f(x2, y2, 0.0);
		}
		else {
			fx = x2;
			fy = y2;
		}
		cache = 1;
		cx = x2;
		cy = y2;
	}
	glVertex3f(x2, y2, 0.0);
	glVertex3f(fx, fy, 0.0);

	glEnd(); // 




	glLineWidth((GLfloat)1.0); // back to normal line width 
	glEnable(GL_LINE_SMOOTH);
	glFlush(); // drawing the object to screen 


	
	
	

}

// Part 3: init
void init(void){
	cout << glGetString(GL_VERSION) << "\n";
	cout << glGetString(GL_VENDOR) << "\n";
	glClearColor(255.0 / 255, 228.0 / 255, 181.0 / 255, 0.0);  // select background color: white
	glColor3f(1.0, 0.0, 0.0); // select drawing color: pink
	glPointSize(7.0); // 70 pixel dot!
	glMatrixMode(GL_PROJECTION); // initialize viewing values
	glLoadIdentity(); //
	glOrtho(0.0, w, 0.0, h, -1.0, 1.0); // specify coordinate system
	
}

// Part 4: main
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Declare display mode (single buffer and RGBA)
	glutInitWindowSize(w, h); // Declare initial window size
	// glutInitWindowPosition (0.5, 0.5); //Declare display(draw) position
	glutCreateWindow("Olympic Logo by LK_Hao"); // Open window with label, could use arg[0]
	init(); // Call initialization routines for preparing display
	glutDisplayFunc(display);  // Register callback function to display graphics
	glutMainLoop(); // Enter main loop and process events.
	return 0; /* ISO C requires main to return int. */
}
