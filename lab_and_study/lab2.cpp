/*
 LiKunhao
*/

#include<GL/glew.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

#include<iostream>//dot.cpp
using std::cout;

GLfloat w=600.0;//set the size:(600,600);
GLfloat h=600.0;

void display(void)
{	
	double x(0.1);
	double y(0.1);
	double xnew(0.0);
	double ynew(0.0);
	int iter(100000);
	double a(1.0); // coefficients for "The King's Dream"
	double b(2.0);
	double c(1.0);
	double d(1.0);
	glClear (GL_COLOR_BUFFER_BIT); // set selected background color by glClearColor()
	glBegin(GL_POINTS); // construct an object
	for (int i=0; i<iter; i++) 
	{
		xnew = sin(y*b) + c*sin(x*b);
		ynew = sin(x*a) + d*sin(y*a); 
		x = xnew; 
		y = ynew; 
		glColor3f(1, (1-y), (0.01+x));   //select drawing color
		glVertex3f(x*125.0+300, y*125.0+300, 0.0f); //the size is 600,600 ,so this is 300,300to show the object
	}
	glEnd(); //
	glFlush ();  // drawing the object to screen
}

void init (void)
{
	cout<<glGetString(GL_VERSION) <<"\n";
	cout<<glGetString(GL_VENDOR) <<"\n";
	glClearColor(0.0,0.0,0.0, 0.0);// select background color: black 
	//glClearColor(32 / 255.0, 126 / 255.0, 158 / 255.0, 0.0);// select background color: R32,G126,B158,GLclampf alpha 0;
	//glColor3f(32 / 255.0, 0.8, 0.7); // select drawing color: pink 
	glPointSize(1.0); // 10 pixel dot!
	glMatrixMode(GL_PROJECTION); // initialize viewing values
	glLoadIdentity(); //
	glOrtho(0.0, w, 0.0, h, -1.0, 1.0); // specify coordinate system
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); //Declare display mode (single buffer and RGBA)
	glutInitWindowSize (w, h); // Declare initial window size 
	// glutInitWindowPosition (0.5, 0.5); //Declare display(draw) position
	glutCreateWindow ("LiKunhao's dream:"); // Open window with label, could use arg[0]
	init (); // Call initialization routines for preparing display
	glutDisplayFunc(display);  // Register callback function to display graphics
	glutMainLoop(); // Enter main loop and process events.
	return 0; /* ISO C requires main to return int. */
}


