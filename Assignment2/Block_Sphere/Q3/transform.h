
#include <math.h>
#include <iostream>
using namespace std;
#include <GL/glut.h>

#define toRad(a) a*3.14/180

void translate(GLfloat x, GLfloat y, GLfloat z);
void rotate1(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void scale(GLfloat x, GLfloat y, GLfloat z);
void shear(GLfloat xy, GLfloat xz, GLfloat yx, GLfloat yz, GLfloat zx, GLfloat zy);
void rotate(GLfloat angle, GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
void matrixMult(GLfloat *,GLfloat *);
void setCurrent(GLfloat *);

void translate(GLfloat x, GLfloat y, GLfloat z) {
	GLfloat t[] = {1,0,0,0,0,1,0,0,0,0,1,0,x,y,z,1};
	setCurrent(t);
	//glMultMatrixf(t);
}

void scale(GLfloat x, GLfloat y, GLfloat z) {
	GLfloat t[] = {x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1};
	setCurrent(t);
	//glMultMatrixf(t);
}

void rotate(GLfloat angle, GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2){
	angle = toRad(angle);
	GLfloat a = x2-x1;
	GLfloat b = y2-y1;
	GLfloat c = z2-z1;

	GLfloat V = sqrt(a*a+b*b+c*c);
	a /= V;
	b /= V;
	c /= V;
	GLfloat d = sqrt(b*b+c*c);
	GLfloat o[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,o);
	//cout << a << b<<c<<d<<endl;
	//translate(-x1,-y1,-z1);
	GLfloat t[] = {1,0,0,0,0,1,0,0,0,0,1,0,-x1,-y1,-z1,1};
	matrixMult(t,o);
	if(d != 0){
		GLfloat Rx[] = {1,0,0,0,0,c/d,b/d,0,0,-b/d,c/d,0,0,0,0,1};
		matrixMult(Rx,o);
	}
	GLfloat Ry[] = {d,0,a,0,0,1,0,0,-a,0,d,0,0,0,0,1};
	matrixMult(Ry,o);
	GLfloat Rz[] = {cos(angle),sin(angle),0,0,-sin(angle),cos(angle),0,0,0,0,1,0,0,0,0,1};
	matrixMult(Rz,o);
	GLfloat Ryi[] = {d,0,-a,0,0,1,0,0,a,0,d,0,0,0,0,1};
	matrixMult(Ryi,o);
	if(d != 0){
		GLfloat Rxi[] = {1,0,0,0,0,c/d,-b/d,0,0,b/d,c/d,0,0,0,0,1};
		matrixMult(Rxi,o);
	}
	GLfloat ti[] = {1,0,0,0,0,1,0,0,0,0,1,0,x1,y1,z1,1};
	matrixMult(ti,o);
	/*for(int i=0;i<16;i++)
		cout << o[i] << "  ";
	cout << endl;*/
	glLoadMatrixf(o);
}

void rotate1(GLfloat angle, GLfloat x, GLfloat y, GLfloat z){
	angle = toRad(angle);
	if(x){
		GLfloat t[] = {1,0,0,0,0,cos(angle),sin(angle),0,0,-sin(angle),cos(angle),0,0,0,0,1};
		setCurrent(t);
		//glMultMatrixf(t);
	}
	if(y){
		GLfloat t[] = {cos(angle),0,-sin(angle),0,0,1,0,0,sin(angle),0,cos(angle),0,0,0,0,1};
		setCurrent(t);
		//glMultMatrixf(t);
	}
	if(z){
		GLfloat t[] = {cos(angle),sin(angle),0,0,-sin(angle),cos(angle),0,0,0,0,1,0,0,0,0,1};
		setCurrent(t);
		//glMultMatrixf(t);
	}
}

void shear(GLfloat xy, GLfloat xz, GLfloat yx, GLfloat yz, GLfloat zx, GLfloat zy) {
	GLfloat t[] = {1,yx,zx,0,xy,1,zy,0,xz,yz,1,0,0,0,0,1};
	setCurrent(t);
	//glMultMatrixf(t);
}

void matrixMult(GLfloat *A,GLfloat *B){
	GLfloat temp;
	GLfloat result[4][4] = {0};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			temp = 0;
			for(int k=0;k<4;k++)
				temp += A[k*4+i]*B[j*4+k];
			result[i][j] = temp;
		}
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			B[4*j+i] = result[i][j];
			//cout << result[i][j] << "  ";
		}
	//cout << "\n\n";
}

void setCurrent(GLfloat *t){
	GLfloat o[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,o);
	matrixMult(t,o);
	glLoadMatrixf(o);
}