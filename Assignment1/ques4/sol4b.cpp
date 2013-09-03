
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>

double rotate_y=0; 
double rotate_x=0;
#include <bits/stdc++.h>

using namespace std;
// Usefull macros
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<string> vs;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 

#define present(c,x) ((c).find(x) != (c).end())  // for set/map etc 
#define cpresent(c,x) (find(all(c),x) != (c).end())  // for vector 

float cube_vert[48] = {
						 0.0,0.0,0.0,
						 1.0,0.0,0.0,
						 1.0,0.0,1.0,
						 0.0,0.0,1.0,
						 
						 1.0,1.0,0.0,
						 1.0,1.0,1.0,
						 0.0,1.0,1.0,
						 0.0,1.0,0.0,
						 
						 1.0,1.0,0.0,
						 1.0,1.0,1.0,
						 0.0,1.0,1.0,
						 0.0,1.0,0.0,
						 
						 0.0,0.0,0.0,
						 1.0,0.0,0.0,
						 1.0,0.0,1.0,
						 0.0,0.0,1.0
						 	
					};
int det_d(vector<int> mat, int d) {
    if( d == 1) return mat[0];
    int total = 0;
    forn(j, d) {
        int mul;
        if(j%2) mul = -mat[j];
        else mul = mat[j];
        
        vector<int> mat1(mat.begin()+d, mat.end());
        forn(i, d-1) {
            //cout << i+1 << " " << j << " " << d<< endl;
            mat1.erase(mat1.begin() + (d-i-2)*d+j);
        }
        total += mul*det_d(mat1, d-1);
    }
    return total;
}

vector<pair<int, ii> > triangulate_convex(vector<pair<int, ii> > &v) {
    vector<pair<int, ii> > ans;
    forn(i, sz(v)) {
        forn(j, sz(v)) {
            if( j <= i ) continue;
            forn(k, sz(v)) {
                if(k <= i || k <= j) continue;
                // checking for the plane (made with ith, jth and kth point) , with all the other points.
                vector<int> dets;
                forn(l, sz(v)) {
                    if(i==l || j==l || k==l) continue;
                    vector<int> mat;
                    mat.pb(v[i].first);
                    mat.pb(v[i].second.first);
                    mat.pb(v[i].second.second);
                    mat.pb(1);

                    mat.pb(v[j].first);
                    mat.pb(v[j].second.first);
                    mat.pb(v[j].second.second);
                    mat.pb(1);
                
                    mat.pb(v[k].first);
                    mat.pb(v[k].second.first);
                    mat.pb(v[k].second.second);
                    mat.pb(1);
                
                    mat.pb(v[l].first);
                    mat.pb(v[l].second.first);
                    mat.pb(v[l].second.second);
                    mat.pb(1);
                    int x = det_d(mat, 4);
                    if(x)
                    dets.pb(x);
                }
                bool yes = true;
                if(dets.size() > 0) {
                    forn(q, sz(dets)) {
                        if(dets[0]*dets[q] < 0) {
                            yes = false;
                            break;
                        }
                    }
                }
                if(yes) ans.pb(mp(i, mp(j,k)));
            }
        }
    }
    return ans;
}

void display(){
 
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // Reset transformations
  glLoadIdentity();
 
  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 
  vector<pair<int, ii> > v;
  	for(int i = 0; i < 16; i++)
  	{
  		v.pb(mp(cube_vert[i], mp(cube_vert[i+1], cube_vert[i+2])));
  	}
    
    
    vector<pair<int, ii > >ans = triangulate_convex(v);
    forn(i, sz(ans)) {
	int x=ans[i].first, y=ans[i].second.first, z=ans[i].second.second;
	glBegin(GL_TRIANGLE_STRIP);
        	glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
        	glVertex3f(v[x].first, v[x].second.first, v[x].second.second);
        	glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
        	glVertex3f(v[y].first, v[y].second.first, v[y].second.second);
        	glColor3f((float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX,(float)rand()/(float)RAND_MAX);
        	glVertex3f(v[z].first, v[z].second.first, v[z].second.second);
    	glEnd();
    }
 
  glFlush();
  glutSwapBuffers();
 
}

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
 
  //  Request display update
  glutPostRedisplay();
 
}
 
int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 
  // Create window
  glutCreateWindow("Awesome Mesh");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}
