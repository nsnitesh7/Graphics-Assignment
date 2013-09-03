#include <GL/glut.h>

// Global Variables
double rotate_y          = 0.0;
double rotate_x          = 0.0;
double zoom              = 0.3;
// Constants
const double rotate_step = 5.0;
const double zoom_step   = 0.01;

void reshape(int width, int height);
void keyboard(unsigned char key, int x, int y);
void drawMesh();
void drawTriangle(GLfloat a[3],GLfloat b[3],GLfloat c[3],int color[3]);


void reshape(int width, int height)
{
	if (height == 0)
		height = 1;

	glViewport(0, 0, width, height);
	glOrtho(0.0, width, 0.0, height, 0, 50000);
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
void drawTriangle(GLfloat a[3],GLfloat b[3],GLfloat c[3],int color[3])
{
	glBegin(GL_LINES);
	glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
	//glColor3f(color[0],color[1],color[2]);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(c);
	glVertex3fv(a);
	glEnd();
}

void drawMesh()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glScaled(zoom, zoom, zoom);
	GLfloat vertexListObject1red[48][3]={{0,0,0},{0.5,0,0},{0.5,0.75,0},{0,0,0},{0.5,0.75,0},{0,0.75,0},
	{0,0,-1},{0.5,0,-1},{0.5,0.75,-1},{0,0,-1},{0.5,0.75,-1},{0,0.75,-1},
	{0.5,0.5,0},{1,0.5,0},{1,0.75,0},{0.5,0.5,0},{1,0.75,0},{0.5,0.75,0},
	{0.5,0.5,-1},{1,0.5,-1},{1,0.75,-1},{0.5,0.5,-1},{1,0.75,-1},{0.5,0.75,-1},
	{0.25,0.75,0},{0.5,0.75,0},{0.5,1,0},{0.25,0.75,0},{0.5,1,0},{0.25,1,0},
	{0.25,0.75,-1},{0.5,0.75,-1},{0.5,1,-1},{0.25,0.75,-1},{0.5,1,-1},{0.25,1,-1},
	{0.75,0.75,0},{1,0.75,0},{1,1,0},{0.75,0.75,0},{1,1,0},{0.75,1,0},
	{0.75,0.75,-1},{1,0.75,-1},{1,1,-1},{0.75,0.75,-1},{1,1,-1},{0.75,1,-1}};
	
	for(int i=0;i<48;i+=3)
	{
	    int color[3] = {1,0,0};
		drawTriangle(vertexListObject1red[i],vertexListObject1red[i+1],vertexListObject1red[i+2],color);
	}

	GLfloat vertexListObject1yellow[18][3]={{0,0,0},{0,0,-1},{0,0.75,-1},{0,0,0},{0,0.75,-1},{0,0.75,0},
	{0.25,0.75,0},{0.25,0.75,-1},{0.25,1,-1},{0.25,0.75,0},{0.25,1,-1},{0.25,1,0},
	{0.75,0.75,0},{0.75,0.75,-1},{0.75,1,-1},{0.75,0.75,0},{0.75,1,-1},{0.75,1,0}};
	for(int i=0;i<18;i+=3){
		int color[3] = {1,1,0};
		drawTriangle(vertexListObject1yellow[i],vertexListObject1yellow[i+1],vertexListObject1yellow[i+2],color);
	}

	GLfloat vertexListObject1blue[18][3]={{0.5,0,0},{0.5,0.5,0},{0.5,0.5,-1},{0.5,0,0},{0.5,0.5,-1},{0.5,0,-1},
	{1,0.5,0},{1,1,0},{1,1,-1},{1,0.5,0},{1,1,-1},{1,0.5,-1},
	{0.5,0.75,0},{0.5,1,0},{0.5,1,-1},{0.5,0.75,0},{0.5,1,-1},{0.5,0.75,-1}};
	for(int i=0;i<18;i+=3){
		int color[3] = {0,0,1};
		drawTriangle(vertexListObject1blue[i],vertexListObject1blue[i+1],vertexListObject1blue[i+2],color);
	}

	GLfloat vertexListObject1skyblue[12][3]={{0,0,0},{0.5,0,0},{0.5,0,-1},{0,0,0},{0.5,0,-1},{0,0,-1},
	{0.5,0.5,0},{0.5,0.5,-1},{1,0.5,-1},{0.5,0.5,0},{1,0.5,-1},{1,0.5,0}};
	for(int i=0;i<12;i+=3){
		int color[3] = {0,1,1};
		drawTriangle(vertexListObject1skyblue[i],vertexListObject1skyblue[i+1],vertexListObject1skyblue[i+2],color);
	}
	GLfloat vertexListObject1pink[24][3]={{0,0.75,0},{0,0.75,-1},{0.25,0.75,-1},{0,0.75,0},{0.25,0.75,-1},{0.25,0.75,0},
	{0.5,0.75,0},{0.5,0.75,-1},{0.75,0.75,-1},{0.5,0.75,0},{0.75,0.75,-1},{0.75,0.75,0},
	{0.25,1,0},{0.25,1,-1},{0.5,1,-1},{0.25,1,0},{0.5,1,-1},{0.5,1,0},
	{0.75,1,0},{0.75,1,-1},{1,1,-1},{0.75,1,0},{1,1,-1},{1,1,0}};
	for(int i=0;i<24;i+=3){
		int color[3] = {1,0,1};
		drawTriangle(vertexListObject1pink[i],vertexListObject1pink[i+1],vertexListObject1pink[i+2],color);
	}

	glPushMatrix(); 

	float a=0.0+2.0,b=0.5+2.0,c=1.0+2.0,z=-1.0+2.0;
	GLfloat vertexListObject2red[24][3]={{a,a,a},{c,a,a},{c,b,a},{a,a,a},{c,b,a},{a,b,a},
	{a,a,z},{c,a,z},{c,b,z},{a,a,z},{c,b,z},{a,b,z},
	{a,b,a},{b,b,a},{b,c,a},{a,b,a},{b,c,a},{a,c,a},
	{a,b,z},{b,b,z},{b,c,z},{a,b,z},{b,c,z},{a,c,z}};
	for(int i=0;i<24;i+=3){
		int color[3] = {1,0,0};
		drawTriangle(vertexListObject2red[i],vertexListObject2red[i+1],vertexListObject2red[i+2],color);
	}

	GLfloat vertexListObject2yellow[24][3]={{a,a,a},{a,c,a},{a,c,z},{a,a,a},{a,c,z},{a,a,z}};
	for(int i=0;i<6;i+=3){
		int color[3] = {1,0,0};
		drawTriangle(vertexListObject2yellow[i],vertexListObject2yellow[i+1],vertexListObject2yellow[i+2],color);
	}

	GLfloat vertexListObject2blue[24][3]={{c,a,a},{c,a,z},{c,b,z},{c,a,a},{c,b,z},{c,b,a},
	{b,b,a},{b,c,a},{b,c,z},{b,b,a},{b,c,z},{b,b,z}};
	for(int i=0;i<12;i+=3){
		int color[3] = {0,1,0};
		drawTriangle(vertexListObject2blue[i],vertexListObject2blue[i+1],vertexListObject2blue[i+2],color);
	}

	GLfloat vertexListObject2skyblue[24][3]={{a,a,a},{a,c,a},{a,c,z},{a,a,a},{a,c,z},{a,a,z}};
	for(int i=0;i<6;i+=3){
		int color[3] = {1,1,0};
		drawTriangle(vertexListObject2skyblue[i],vertexListObject2skyblue[i+1],vertexListObject2skyblue[i+2],color);
	}

	GLfloat vertexListObject2pink[24][3]={{a,c,a},{a,c,z},{b,c,z},{a,c,a},{b,c,z},{b,c,a},
	{b,b,a},{b,b,z},{c,b,z},{b,b,a},{c,b,z},{c,b,a}};
	for(int i=0;i<12;i+=3){
		int color[3] = {1,0,1};
		drawTriangle(vertexListObject2pink[i],vertexListObject2pink[i+1],vertexListObject2pink[i+2],color);
	}
	glTranslatef(-3.0, -3.0, -3.0);  /* Move the coord sys here */
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(1600, 900);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1600) / 2,(glutGet(GLUT_SCREEN_HEIGHT) - 900) / 2);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Traingular mesh");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(drawMesh);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}