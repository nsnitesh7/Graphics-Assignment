/*
	sample input
	2 11101000 2 11101000 2 11101000 2 11101000 2 11101000 2 11101000 2 11101000 2 11101000
	1 1 1 1 1 1 1 1
*/
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

// Global Variables
double rotate_y          = 0.0;
double rotate_x          = 0.0;
double zoom              = 1.0;

// Constants
const double rotate_step = 5.0;
const double zoom_step   = 0.01;
const double cube_size   = 0.5;
const double cube_size2   = 0.5;
const double center_x    = -0.5;
const double center_y    = -0.5;
const double center_z    = -0.5;
const double center_x2    = 0.5;
const double center_y2    = 0.5;
const double center_z2    = 0.5;

// Example octree for a cube grid: "2", "1" and "0" are the symbols for dirty,
// filled and empty nodes, respectively
string tree;
string tree2;

const char EMPTY  = '0';
const char FILLED = '1';
const char DIRTY  = '2';

void drawCube(double center_x, double center_y, double center_z, double size)
{
    double half_size = size / 2.0;
    double front     = center_z - half_size;
    double back      = center_z + half_size;
    double left      = center_x - half_size;
    double right     = center_x + half_size;
    double bottom    = center_y - half_size;
    double top       = center_y + half_size;

    glPushMatrix();

    // red side - front
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(right, bottom, front);
    glVertex3f(right, top,    front);
    glVertex3f(left,  top,    front);
    glVertex3f(left,  bottom, front);
    glEnd();

    // green side - back
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(right, bottom, back);
    glVertex3f(right, top,    back);
    glVertex3f(left,  top,    back);
    glVertex3f(left,  bottom, back);
    glEnd();

    // blue side - right
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(right, bottom, front);
    glVertex3f(right, top,    front);
    glVertex3f(right, top,    back);
    glVertex3f(right, bottom, back);
    glEnd();

    // yellow side - left
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(left, bottom, back);
    glVertex3f(left, top,    back);
    glVertex3f(left, top,    front);
    glVertex3f(left, bottom, front);
    glEnd();

    // magneta side - top
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(right, top, back);
    glVertex3f(right, top, front);
    glVertex3f(left,  top, front);
    glVertex3f(left,  top, back);
    glEnd();

    // cyan side - bottom
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(right, bottom, front);
    glVertex3f(right, bottom, back);
    glVertex3f(left,  bottom, back);
    glVertex3f(left,  bottom, front);
    glEnd();

    glPopMatrix();
}
int drawOctree(const string& tree, size_t pos, double center_x, double center_y,
               double center_z, double cube_size)
{
    // bad-formed tree
    assert(pos < tree.size());
    // unrecognized char
    assert(tree[pos] == EMPTY || tree[pos] == FILLED || tree[pos] == DIRTY);

    if (tree[pos] == EMPTY)
    {
        return pos + 1;
    }
    else if (tree[pos] == FILLED)
    {
        drawCube(center_x, center_y, center_z, cube_size);
        return pos + 1;
    }
    else // tree[pos] == DIRTY
    {
        double new_cube_size = cube_size / 2.0;
        double bias          = new_cube_size / 2.0;
        double left          = center_x - bias;
        double right         = center_x + bias;
        double bottom        = center_y - bias;
        double top           = center_y + bias;
        double front         = center_z - bias;
        double back          = center_z + bias;

        pos += 1;
        pos = drawOctree(tree, pos, left,  bottom, back,  new_cube_size);
        pos = drawOctree(tree, pos, right, bottom, back,  new_cube_size);
        pos = drawOctree(tree, pos, left,  top,    back,  new_cube_size);
        pos = drawOctree(tree, pos, right, top,    back,  new_cube_size);
        pos = drawOctree(tree, pos, left,  bottom, front, new_cube_size);
        pos = drawOctree(tree, pos, right, bottom, front, new_cube_size);
        pos = drawOctree(tree, pos, left,  top,    front, new_cube_size);
        pos = drawOctree(tree, pos, right, top,    front, new_cube_size);

        return pos;
    }
}
void drawOctree(const string& tree, double center_x, double center_y,
                double center_z, double cube_size)
{
    drawOctree(tree, 0, center_x, center_y, center_z, cube_size);
}



void reshape(int width, int height);
void display();
void keyboard(unsigned char key, int x, int y);

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);
    glOrtho(0.0, width, 0.0, height, 0, 50000);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glScaled(zoom, zoom, zoom);

    drawOctree(tree, center_x, center_y, center_z, cube_size);
    drawOctree(tree2, center_x2, center_y2, center_z2, cube_size2);

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
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

string removeSpaces(string s)
{
	string ret="";
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]!=' ')
			ret+=s[i];
	}
	return ret;
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 600) / 2,(glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
	
	//Input1
	getline(cin,tree);
	tree=removeSpaces(tree);
	
	//Input2
	getline(cin,tree2);
	tree2=removeSpaces(tree2);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Octree");

    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

