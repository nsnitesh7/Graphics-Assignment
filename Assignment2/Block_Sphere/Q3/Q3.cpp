#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "q2.h"
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#define PI 3.1415926535897 
#define toRad(a) a*3.14/180
/* Global variables */
char title[] = "Scene of 3D Objects";

void display();
void specialKeys();
void drawSphere(float);
void drawCube(double originX, double originY, double originZ, double size);

double rotate_y=0; 
double rotate_x=0;
double zoom = 1.0;
float sphereRadius = 1;
float cubeX = 0, cubeY = 0, cubeZ = 0, cubeSize = 1;
//-----------------------------------------------------------

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
  
}
 
//render function which creates different objects 
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 

	//-------------------------------------------House------------------------------
	glLoadIdentity();                 // Reset the model-view matrix

	// Rotate / zoom when user changes rotate_x and rotate_y
	scale(zoom,zoom,zoom);
	//rotate(rotate_x,-1.0,-1.0,0.0,0.0,-1.0,0.0);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(0.0f, 0.0f, -9.0f);
	drawCube(0.0, 0.0, 0.0, 2.0);

	glLoadIdentity();
	scale(zoom*1.4,zoom,zoom);
	rotate(45,-1.0,0.0,0.0,0.0,0.0,0.0);
	//rotate(rotate_x,-1.0,-1.0,0.0,0.0,-1.0,0.0);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(0.0f, 1.0f, -9.0f);
	drawCube(0.0, 0.0, 0.0, 1.4);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(0.0f, 0.0f, -7.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(3);

	//-------------------------------------------tree------------------------------
	glLoadIdentity();                 // Reset the model-view matrix

	scale(zoom,zoom*1.5,zoom);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(3.0f, 2.0f, -9.0f);
	glColor3f(0.0,1.0,0.0);
	drawSphere(1.0);
	
	glLoadIdentity();                 // Reset the model-view matrix
	scale(zoom*0.4,zoom*2,zoom*0.4);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(3.0f, 0.0f, -9.0f);
	
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	//-------------------------------------------tree------------------------------
	glLoadIdentity();                 // Reset the model-view matrix

	scale(zoom*0.8,zoom*1.2,zoom*0.8);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(2.0f, 2.0f, -9.0f);
	glColor3f(0.0,1.0,0.0);
	drawSphere(1.0);
	
	glLoadIdentity();                 // Reset the model-view matrix
	scale(zoom*0.4,zoom*2,zoom*0.4);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(2.0f, 0.0f, -9.0f);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	//-----------------Snow Man --------------------------------------------

	glLoadIdentity();
	scale(0.3*zoom,0.7*zoom,0.8*zoom);
	//shear(1.0,0,1.0,0,0,0);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(-6.0f, -0.3f, -9.0f);
	glColor3f(1.0,1.0,1.0);
	drawSphere(1.0);

	glLoadIdentity(); 
	scale(0.2*zoom,0.5*zoom,0.6*zoom);
	//shear(1.0,0,1.0,0,0,0);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(-6.0f, 0.6f, -9.0f);
	glColor3f(1.0,1.0,1.0);
	drawSphere(1.0);

	glLoadIdentity(); 
	scale(0.1*zoom,0.3*zoom,0.4*zoom);
	//shear(1.0,0,1.0,0,0,0);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(-6.0f, 1.2f, -9.0f);
	glColor3f(1.0,1.0,1.0);
	drawSphere(1.0);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-5.45f, 1.2f, -8.0f);
	glColor3f(1.0,0.0,0.0);
	drawSphere(0.4);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-5.25f, 1.2f, -8.0f);
	glColor3f(1.0,0.0,0.0);
	drawSphere(0.4);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-5.35f, 1.0f, -8.0f);
	glColor3f(1.0,0.5,0.0);
	drawSphere(0.4);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-5.35f, 0.7f, -8.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.4);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-5.35f, 0.45f, -8.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.4);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-5.35f, 0.2f, -8.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.4);

	//-------------------------------------------road------------------------------
	glLoadIdentity();
	glColor3f(0.752941,0.752941,0.752941);
	glTranslatef(-1.0f, -1.0f, -9.0f);
	glRotatef(180,1.0,0.0,0.0);
	glScalef(zoom*2.5,0.05,zoom*2);
	drawCube(0.0, 0.0, 0.0, 5);


	//-------------------------------------------character------------------------------
	glLoadIdentity();
	scale(zoom,zoom,zoom);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(-3.0f, 3.0f, -9.0f);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-2.8f, 2.7f, -7.0f);
	glColor3f(1.0,0.0,0.0);
	drawSphere(1.0);

	glLoadIdentity();
	scale(0.1,0.1,0.1);
	translate(-2.2f, 2.7f, -7.0f);
	glColor3f(1.0,0.0,0.0);
	drawSphere(1.0);

	glLoadIdentity();
	scale(zoom,zoom*1.5,zoom);
	rotate(rotate_y+90,0.0,0.0,0.0,0.0,1.0,0.0);
	translate(-3.0f, 1.5f, -9.0f);
	drawCube(cubeX, cubeY, cubeZ, cubeSize*1.5);
	
	glLoadIdentity();
	scale(zoom*0.1,zoom*2,zoom*0.1);
	rotate(rotate_y,-0.5,0.0,0.0,-0.5,1.0,0.0);
	translate(-2.5f, 0.0f, -9.0f);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);
	
	glLoadIdentity();
	scale(zoom*0.1,zoom*2,zoom*0.1);
	rotate(rotate_y,0.5,0.0,0.0,0.5,1.0,0.0);
	translate(-3.5f, 0.0f, -9.0f);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

//draw block using vertex lists
void drawCube(double originX, double originY, double originZ, double size)
{
	double half = size / 2.0;
	double front     = originZ - half;
	double back      = originZ + half;
	double left      = originX - half;
	double right     = originX + half;
	double bottom    = originY - half;
	double top       = originY + half;

	glPushMatrix();
	
	//Front Face
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(right, bottom, front);
	glVertex3f(right, top,    front);
	glVertex3f(left,  top,    front);
	glVertex3f(left,  bottom, front);
	glEnd();

	//Back Face
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(right, bottom, back);
	glVertex3f(right, top,    back);
	glVertex3f(left,  top,    back);
	glVertex3f(left,  bottom, back);
	glEnd();

	//Right Face
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(right, bottom, front);
	glVertex3f(right, top,    front);
	glVertex3f(right, top,    back);
	glVertex3f(right, bottom, back);
	glEnd();

	//Left Face
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(left, bottom, back);
	glVertex3f(left, top,    back);
	glVertex3f(left, top,    front);
	glVertex3f(left, bottom, front);
	glEnd();

	//Top Face
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(right, top, back);
	glVertex3f(right, top, front);
	glVertex3f(left,  top, front);
	glVertex3f(left,  top, back);
	glEnd();

	//Bottom Face
	glBegin(GL_POLYGON);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(right, bottom, front);
	glVertex3f(right, bottom, back);
	glVertex3f(left,  bottom, back);
	glVertex3f(left,  bottom, front);
	glEnd();

	glPopMatrix();
}

//draw sphere using parametric form and radius
void drawSphere(float radius)
{	
	glPushMatrix ();
	int circle_points = 100;
	glBegin(GL_POINTS); 
	float s=radius;
	float x=-cubeX;
	float y=-cubeY;
	float z=-cubeZ;
	for(int j=0;j<circle_points;j++)
	{
		float phi =2.0*PI*j/circle_points; 
		for (int i = 0; i < circle_points; i++)
		{    
		   float angle =2.0*PI*i/circle_points; 
		   glVertex3f(x+s*cos(phi)*cos(angle), y+s*cos(phi)*sin(angle),z+s*sin(phi)); 
		}
	}
	glEnd();
	glBegin(GL_POINTS); 
	for (int i = 0; i < circle_points; i++)
	{
		
		for(int j=0;j<circle_points;j++)
		{    float phi =2.0*PI*j/circle_points;
		   float angle =2.0*PI*i/circle_points; 
		   glVertex3f(x+s*cos(phi)*cos(angle), y+s*cos(phi)*sin(angle),z+s*sin(phi)); 
		}
	}
	glEnd();

	glPopMatrix ();
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) 
{
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// specialKeys() Callback Function
void specialKeys( int key, int x, int y ) {
 
	if (key == GLUT_KEY_RIGHT)
	rotate_y += 5;
 
	else if (key == GLUT_KEY_LEFT)
	rotate_y -= 5;
 
	else if (key == GLUT_KEY_UP)
	rotate_x += 5;
 
	else if (key == GLUT_KEY_DOWN)
	rotate_x -= 5;
	else if (key == GLUT_KEY_INSERT)
		zoom *= (1.0 + 0.01);
	else if (key == GLUT_KEY_END)
		zoom *= (1.0 - 0.01);
 
	//  Request display update
	glutPostRedisplay();
 
}

/* main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	glutSpecialFunc(specialKeys);
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}