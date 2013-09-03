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

double rotate_y=45; 
double rotate_x=45;
const double zoom_step = 0.01;
int window; 
float dim[500];
float dim2[500];
int size;
int size2;
double zoom = 0.5;
 
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

void display(){
 
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
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

void specialKeys( int key, int x, int y ) {
 cout<<key<<endl;
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;
 
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 5;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;
  glutPostRedisplay();
 
}

void keyboard(unsigned char key, int x, int y)
{
	int rotate_step=5;
    if (key == 'd')
        rotate_y += rotate_step;
    else if (key == 'a')
        rotate_y -= rotate_step;
    else if (key == 'w')
        rotate_x += rotate_step;
    else if (key == 's')
        rotate_x -= rotate_step;
    else if (key == 'q')
        zoom *= (1.0 + zoom_step);
    else if (key == 'e')
        zoom *= (1.0 - zoom_step);

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
    window = glutCreateWindow("cube by vertex list");  
	int it;
	printf("enter the size of cube1 ");
	scanf("%d",&size);
	printf("enter the sides of cube1 ");
	for(it = 0;it < size;++it)
	{
		scanf("%f",&dim[it]);
	}
	printf("enter the size of cube2 ");
	scanf("%d",&size2);
	printf("enter the sides of cube2 ");
	for(it = 0;it < size2;++it)
	{
		scanf("%f",&dim2[it]);
	}
 
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
 
  return 0;
 
}
