#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

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

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
  
}
//render the objects 
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 

	//-------------------------------------------House------------------------------
	glLoadIdentity();                 // Reset the model-view matrix

	glTranslatef(0.0f, 0.0f, -9.0f);
	glScalef(zoom,zoom,zoom);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	glColor3f(1.0, 0.5, 0.0);
	drawCube(0.0, 0.0, 0.0, 2.0);

	glLoadIdentity();
	glTranslatef(0.0f, 1.0f, -9.0f);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	glRotatef(45,1.0,0.0,0.0);
	glScalef(zoom*1.4,zoom,zoom);
	drawCube(0.0, 0.0, 0.0, 1.4);

	glLoadIdentity();
	glScalef(0.1,0.1,0.1);
	glTranslatef(0.0f, 0.0f, -9.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.5);

	

	//-------------------------------------------tree------------------------------
	glLoadIdentity();                 // Reset the model-view matrix

	glTranslatef(3.0f, 2.0f, -9.0f);
	glScalef(zoom,zoom*1.5,zoom);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	glColor3f(0.0,1.0,0.0);
	drawSphere(1.0);

	glLoadIdentity();                 // Reset the model-view matrix
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(3.0f, 0.0f, -9.0f);
	glScalef(zoom*0.4,zoom*2,zoom*0.4);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	//-------------------------------------------tree------------------------------
	glLoadIdentity();                 // Reset the model-view matrix

	glTranslatef(2.0f, 2.0f, -9.0f);
	glScalef(zoom*0.8,zoom*1.2,zoom*0.8);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	glColor3f(0.0,1.0,0.0);
	drawSphere(1.0);

	glLoadIdentity();                 // Reset the model-view matrix
	glColor3f(1.0, 0.5, 0.0);
	glTranslatef(2.0f, 0.0f, -9.0f);
	glScalef(zoom*0.4,zoom*2,zoom*0.4);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	//-----------------Snow Man --------------------------------------------

	glLoadIdentity();
	glScalef(0.5*zoom,0.5*zoom,0.5*zoom);
	glTranslatef(-4.2f, -0.4f, -7.0f);
	glColor3f(1.0,1.0,1.0);
	drawSphere(0.55);
	
	glLoadIdentity(); 
	glScalef(0.3*zoom,0.3*zoom,0.3*zoom);
	glTranslatef(-4.2f, 0.4f, -7.0f);
	glColor3f(1.0,1.0,1.0);
	drawSphere(0.45);

	glLoadIdentity(); 
	glScalef(0.2*zoom,0.2*zoom,0.2*zoom);
	glTranslatef(-4.2f, 1.0f, -7.0f);
	glColor3f(1.0,1.0,1.0);
	drawSphere(0.3);

	glLoadIdentity(); 
	glScalef(0.1,0.1,0.1);
	glTranslatef(-3.1f, 0.8f, -5.0f);
	glColor3f(1.0,0.0,0.0);
	drawSphere(0.03);

	glLoadIdentity(); 
	glScalef(0.1,0.1,0.1);
	glTranslatef(-2.95f, 0.8f, -5.0f);
	glColor3f(1.0,0.0,0.0);
	drawSphere(0.03);

	glLoadIdentity(); 
	glScalef(0.1,0.1,0.1);
	glTranslatef(-3.0f, 0.7f, -5.0f);
	glColor3f(1.0,0.5,0.0);
	drawSphere(0.03);

	glLoadIdentity(); 
	glScalef(0.1,0.1,0.1);
	glTranslatef(-3.0f, 0.5f, -5.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.03);

	glLoadIdentity(); 
	glScalef(0.1,0.1,0.1);
	glTranslatef(-3.0f, 0.35f, -5.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.03);

	glLoadIdentity(); 
	glScalef(0.1,0.1,0.1);
	glTranslatef(-3.0f, 0.2f, -5.0f);
	glColor3f(0.0,0.0,0.0);
	drawSphere(0.03);
	//-------------------------------------------road------------------------------
	glLoadIdentity();
	glColor3f(0.752941,0.752941,0.752941);
	glTranslatef(-1.0f, -1.0f, -12.0f);
	glRotatef(180,1.0,0.0,0.0);
	glScalef(zoom*2,0.1,zoom*2.5);
	drawCube(0.0, 0.0, 0.0, 5);

	//-------------------------------------------character------------------------------
	glLoadIdentity();
	glColor3f(1,1,0);
	glTranslatef(-3.0f, 3.0f, -9.0f);
	glScalef(zoom,zoom,zoom);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	glLoadIdentity();
	glTranslatef(-2.8f, 2.7f, -7.0f);
	glScalef(0.1,0.1,0.1);
	glColor3f(1.0,0.0,0.0);
	drawSphere(1.0);

	glLoadIdentity();
	glTranslatef(-2.2f, 2.7f, -7.0f);
	glScalef(0.1,0.1,0.1);
	glColor3f(1.0,0.0,0.0);
	drawSphere(1.0);

	glLoadIdentity();
	glTranslatef(-3.0f, 1.5f, -9.0f);
	glScalef(zoom,zoom*1.5,zoom);
	glRotatef(rotate_y+90,0.0,1.0,0.0);
	drawCube(cubeX, cubeY, cubeZ, cubeSize*1.5);
	
	glLoadIdentity();
	glTranslatef(-2.5f, 0.0f, -9.0f);
	glScalef(zoom*0.1,zoom*2,zoom*0.1);
	glRotatef(rotate_y,-0.5,1.0,0.0);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);
	
	glLoadIdentity();
	glTranslatef(-3.5f, 0.0f, -9.0f);
	glScalef(zoom*0.1,zoom*2,zoom*0.1);
	glRotatef(rotate_y,0.5,1.0,0.0);
	drawCube(cubeX, cubeY, cubeZ, cubeSize);

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

//draw cube using opengl function
void drawCube(double originX, double originY, double originZ, double size)
{
	glPushMatrix();
	glutSolidCube(size);
	glPopMatrix();
}
//draw sphere using opengl function
void drawSphere(float radius)
{
	glPushMatrix();
	glutSolidSphere(radius,50,50);
	glPopMatrix();
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  
	if (height == 0) height = 1;        
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
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
	glutPostRedisplay();
 
}

/* Main function: GLUT runs as a console application starting at main() */
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