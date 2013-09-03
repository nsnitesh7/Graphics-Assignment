#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library
#include <unistd.h>     // needed to sleep
#include <cmath>
const double zoom_step   = 0.01;
 double zoom              = 0.95;
 double rotate_y=0; 
double rotate_x=0;
void init()	        
{
	
	// Set the current clear color to black and the current drawing color to
	// white.
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(2.0, 2.0, 2.0);

	// Set the camera lens to have a 60 degree (vertical) field of view, an
	// aspect ratio of 4/3, and have everything closer than 1 unit to the
	// camera and greater than 40 units distant clipped away.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 4.0/3.0, 1, 40);

	// Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
	// <0, 1, 0> pointing upward.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}

/* The main drawing function. */
void DrawGLScene()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	
	
	
	glLoadIdentity();
	glScaled(zoom, zoom, zoom);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
 	 glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glTranslatef(0.5f,0.4f,-6.0f);		// Move Left 1.5 Units And Into The Screen 6.0
	
	float x1,y1,x2,y2;
	float angle;
	double radius=.5;
	 
	x1 = 0.5,y1=0.6;
	glColor3f(1.0,1.0,0.6);
	
	/* Solid Sphere */	 
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	double i = 0.0;
	for (angle=1.0f;angle<361.0f;angle+=0.2)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glColor3f(i,0.0,0.0);
		i += 0.02;
		glVertex3f(x2,y2,1.0f);
	}
	glEnd();					

	/* Draw Cube */
	glLoadIdentity();
	glScaled(zoom, zoom, zoom);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
 	 glRotatef( rotate_y, 0.0, 1.0, 0.0 );				
	glTranslatef(1.5f,0.0f,-7.0f);	
	
	//glRotatef(20.0,1.0,0.0,0.0);
	glColor3f(0.7f,0.5f,0.3f);
	glutWireCube(1.0f);

	glTranslatef(-1.8f,-0.4f,-6.0f);		

	/* Draw Solid Tetrahedron */
	glBegin(GL_POLYGON);
	glScaled(zoom, zoom, zoom);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
 	 glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	// front face of pyramid
	glColor3f(1.0f,0.0f,0.0f);			// Set The Color To Red
	glVertex3f(0.0f, 1.0f, 0.0f);		        // Top of triangle (front)
	glColor3f(0.0f,1.0f,0.0f);			// Set The Color To Green
	glVertex3f(-1.0f,-1.0f, 1.0f);		// left of triangle (front)
	glColor3f(0.0f,0.0f,1.0f);			// Set The Color To Blue
	glVertex3f(1.0f,-1.0f, 1.0f);		        // right of traingle (front)	

	// right face of pyramid
	glColor3f(1.0f,0.0f,0.0f);			// Red
	glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Right)
	glColor3f(0.0f,0.0f,1.0f);			// Blue
	glVertex3f( 1.0f,-1.0f, 1.0f);		// Left Of Triangle (Right)
	glColor3f(0.0f,1.0f,0.0f);			// Green
	glVertex3f( 1.0f,-1.0f, -1.0f);		// Right Of Triangle (Right)

	// back face of pyramid
	glColor3f(1.0f,0.0f,0.0f);			// Red
	glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Back)
	glColor3f(0.0f,1.0f,0.0f);			// Green
	glVertex3f( 1.0f,-1.0f, -1.0f);		// Left Of Triangle (Back)
	glColor3f(0.0f,0.0f,1.0f);			// Blue
	glVertex3f(-1.0f,-1.0f, -1.0f);		// Right Of Triangle (Back)

	// left face of pyramid.
	glColor3f(1.0f,0.0f,0.0f);			// Red
	glVertex3f( 0.0f, 1.0f, 0.0f);		// Top Of Triangle (Left)
	glColor3f(0.0f,0.0f,1.0f);			// Blue
	glVertex3f(-1.0f,-1.0f,-1.0f);		// Left Of Triangle (Left)
	glColor3f(0.0f,1.0f,0.0f);			// Green
	glVertex3f(-1.0f,-1.0f, 1.0f);		// Right Of Triangle (Left)
	glColor3f(0.0f,0.0f,1.0f);
	glEnd();					// Done Drawing The Pyramid
	//glTranslatef(-2.5f,1.0f,1.0f);
	glScaled(zoom, zoom, zoom);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
 	 glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	const double PI=3.1415926535897;
	GLint circle_points = 50;
	glBegin(GL_POINTS); 
	float s=1;
	float x=-3;
	float y=3;
	float z=0;
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
	glColor3f(0.0f,1.0f,0.0f);
	circle_points=50;
	glBegin(GL_POINTS);
		for (int i = 0; i < circle_points; i++)
		{    
		   float angle =2.0*PI*i/circle_points; 
		   glVertex3f(x-2*s+s*cos(angle), y-2*s+s*sin(angle),z-2*s); 
		}
	glEnd();
	
	/* Wire Torus */
	glColor3f(1.0f,0.0f,0.0f);
	glPushMatrix ();
	glScaled(zoom, zoom, zoom);
	glRotatef( rotate_x, 1.0, 0.0, 0.0 );
 	glRotatef( rotate_y, 0.0, 1.0, 0.0 );
	glRotatef(30,1.0,0.0,0.0);
	glutWireTorus(0.5, 7.0, 15, 30);
	glPopMatrix ();
	// swap the buffers to display, since double buffering is used.
	glutSwapBuffers();
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
int main(int argc, char **argv) 
{  

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Scene 1");
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop(); 

  return 1;
}



