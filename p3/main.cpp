# include <cstdlib>
#include<windows.h>
# include <cmath>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <GL/glut.h>


using namespace std;

GLfloat vertices[][3] = {
  { -1.0, -1.0, -1.0 },
  {  1.0, -1.0, -1.0 },
  {  1.0,  1.0, -1.0 },
  { -1.0,  1.0, -1.0 },
  { -1.0, -1.0,  1.0 },
  {  1.0, -1.0,  1.0 },
  {  1.0,  1.0,  1.0 },
  { -1.0,  1.0,  1.0 } };

GLfloat normals[][3] = {
  { -1.0, -1.0, -1.0 },
  {  1.0, -1.0, -1.0 },
  {  1.0,  1.0, -1.0 },
  { -1.0,  1.0, -1.0 },
  { -1.0, -1.0,  1.0 },
  {  1.0, -1.0,  1.0 },
  {  1.0,  1.0,  1.0 },
  { -1.0,  1.0,  1.0 } };

GLfloat colors[][3] = {
  { 0.0, 0.0, 0.0 },
  { 1.0, 0.0, 0.0 },
  { 1.0, 1.0, 0.0 },
  { 0.0, 1.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  { 1.0, 0.0, 1.0 },
  { 1.0, 1.0, 1.0 },
  { 0.0, 1.0, 1.0 } };

static GLint axis = 2;
static GLfloat theta[3] = { 0.0, 0.0, 0.0 };

int main ( int argc, char *argv[] );
void colorcube ( );
void display ( );
void mouse ( int btn, int state, int x, int y );
void myReshape ( int w, int h );
void polygon ( int a, int b, int c, int d );
void spinCube ( );


int main ( int argc, char *argv[] )
{
  glutInit ( &argc, argv );
  glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize ( 500, 500 );
  glutInitWindowPosition ( 0, 0 );
  glutCreateWindow ( "Rotating cube" );
  glutReshapeFunc ( myReshape );
  glutDisplayFunc ( display );
  glutIdleFunc ( spinCube );
  glutMouseFunc ( mouse );

  glEnable ( GL_DEPTH_TEST );
  glutMainLoop ( );
  return 0;
}


void colorcube ( )
{
  polygon ( 0, 3, 2, 1 );
  polygon ( 2, 3, 7, 6 );
  polygon ( 0, 4, 7, 3 );
  polygon ( 1, 2, 6, 5 );
  polygon ( 4, 5, 6, 7 );
  polygon ( 0, 1, 5, 4 );

  return;
}

void display ( )
{
  glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glLoadIdentity ( );
  glRotatef ( theta[0], 1.0, 0.0, 0.0 );
  glRotatef ( theta[1], 0.0, 1.0, 0.0 );
  glRotatef ( theta[2], 0.0, 0.0, 1.0 );
  colorcube ( );
  glFlush ( );
  glutSwapBuffers ( );
  return;
}
//****************************************************************************80

void mouse ( int btn, int state, int x, int y )


{
  if ( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
  {
    axis = axis + 1;
  }
  if ( btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN )
  {
    axis = axis + 1;
  }
  if ( btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
  {
    axis = axis + 1;
  }
  axis = axis % 3;

  return;
}
//****************************************************************************80

void myReshape ( int w, int h )


{
  glViewport ( 0, 0, w, h );
  glMatrixMode ( GL_PROJECTION );
  glLoadIdentity ( );

  if ( w <= h )
  {
    glOrtho (
      -2.0, 2.0,
      -2.0 * ( GLfloat ) h / ( GLfloat ) w, 2.0 * ( GLfloat ) h / ( GLfloat ) w,
      -10.0, 10.0 );
  }
  else
  {
    glOrtho (
      -2.0 * ( GLfloat ) h / ( GLfloat ) w, 2.0 * ( GLfloat ) h / ( GLfloat ) w,
      -2.0, 2.0,
      -10.0, 10.0 );
  }

  glMatrixMode ( GL_MODELVIEW );

  return;
}
//****************************************************************************80

void polygon ( int a, int b, int c, int d )


{
  glBegin ( GL_POLYGON );

  glColor3fv ( colors[a] );
  glNormal3fv ( normals[a] );
  glVertex3fv ( vertices[a] );

  glColor3fv ( colors[b] );
  glNormal3fv ( normals[b] );
  glVertex3fv ( vertices[b] );

  glColor3fv ( colors[c] );
  glNormal3fv ( normals[c] );
  glVertex3fv ( vertices[c] );

  glColor3fv ( colors[d] );
  glNormal3fv ( normals[d] );
  glVertex3fv ( vertices[d] );

  glEnd ( );

  return;
}
//****************************************************************************80

void spinCube ( )


{
  theta[axis] = theta[axis] + 0.020;
  if ( 360.0 < theta[axis] )
  {
    theta[axis] = theta[axis] - 360.0;
  }
  glutPostRedisplay ( );

  return;
}
