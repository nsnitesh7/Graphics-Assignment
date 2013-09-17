#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#define toRad(a) a*3.14/180
 #define PI 3.1415926535897 
/* Global variables */
char title[] = "Scene of 3D Objects";

void display();
void specialKeys();
void drawSphere(float);
void drawCube(double originX, double originY, double originZ, double size);
double rotate_y=0; 
double rotate_x=0;
double zoom = 1.0;
float sphereRadius;
float cubeX, cubeY, cubeZ, cubeSize;

//initialise the functions
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
  
}

//main render function 
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
	// Render a color-cube consisting of 6 quads with different colors
	glLoadIdentity();                 // Reset the model-view matrix
	glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	glScalef(zoom,zoom,zoom);
	glTranslatef(-1.0f, -1.0f, -7.0f);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	glLoadIdentity();                 // Reset the model-view matrix
	glRotatef(rotate_x, 1.0, 0.0, 0.0 );
	glRotatef(rotate_y, 0.0, 1.0, 0.0 );
	glScalef(zoom,zoom,zoom);
	glTranslatef(2.0f, 1.0f, -7.0f);
	glColor3f(0.7,0.7,0.7);
	drawSphere(sphereRadius);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
//function to draw the cube and takes size as user input
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
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(right, bottom, front);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(right, top,    front);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(left,  top,    front);
	glColor3f(1.0, 0.0, 1.0);
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
	glColor3f(1.0, 1.0, 0.0);
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
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(right, bottom, front);
	glVertex3f(right, bottom, back);
	glVertex3f(left,  bottom, back);
	glVertex3f(left,  bottom, front);
	glEnd();

	glPopMatrix();
}

//draw shepre using parametric form and takes radius as user input
void drawSphere(float radius){
	glPushMatrix ();
	int circle_points = 50;
	glBegin(GL_POINTS); 
	glColor3f(0.0f,0.0f,1.0f);
	//glColor3f(0.0, 0.0, 0.0);
	float s=radius;
	float x=-cubeX;
	float y=-cubeY;
	float z=-cubeZ;
	//draw the horizontal rings 
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
	//draw the vertical rings
	glBegin(GL_POINTS); 
	glColor3f(0.0f,0.0f,1.0f);
	//glColor3f(0.0, 0.0, 0.0);
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
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);
	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
//special keyboard keys to roatate and translate 
void specialKeys( int key, int x, int y ) {
 
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
	else if (key == GLUT_KEY_INSERT)
		zoom *= (1.0 + 0.01);
	else if (key == GLUT_KEY_END)
		zoom *= (1.0 - 0.01);
 
	//  Request display update
	glutPostRedisplay();
 
}

//main 
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffered mode
	glutInitWindowSize(640, 480);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	printf("Enter radius of the of the sphere: \n");
	scanf("%f",&sphereRadius);
	printf("Enter origin for the cube(x y z): \n");
	scanf("%f%f%f",&cubeX, &cubeY, &cubeZ);
	printf("Enter size of the cube: \n");
	scanf("%f",&cubeSize);
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);       // Register callback handler for window re-size event
	glutSpecialFunc(specialKeys);
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the infinite event-processing loop
	return 0;
}