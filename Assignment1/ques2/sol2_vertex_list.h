#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display();
float dim[500];
float dim2[500];
int size;
int size2;
 
void create_cube(float *dim,int size)
{
	for(int it = 0;it < size;it = it+3)
	{
		if(it < 12)
		 	glColor3f(0.0f,1.0f,0.0f);
		else if(it < 24)
			glColor3f(1.0f,0.5f,0.0f);	
		else if(it < 36)
 			glColor3f(1.0f,0.0f,0.0f);	
		else if(it < 48)
			glColor3f(1.0f,1.0f,0.0f);
		else if(it < 60)
			glColor3f(0.0f,0.0f,1.0f);	
		else if(it < 72)
			glColor3f(1.0f,0.0f,1.0f);	
		glVertex3f( dim[it], dim[it+1], dim[it+2]);	
	
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();											 //replaces the current matrix with the identity matrix
	glScaled(zoom, zoom, zoom);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glTranslatef(-0.5,-0.5,-0.5);
	glBegin(GL_POLYGON);
		create_cube(dim,size);
		glEnd();
		glTranslatef(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
		create_cube(dim2,size);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

