#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>

void display_points()
{
    glClearColor(0.0,0.0,0.0,0);
	gluOrtho2D(-780 , 780 , -420 , 420);
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(320,240);
    glEnd();
    glFlush();
}



int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1000, 768);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Window");
  glutDisplayFunc(display_points);
  glutMainLoop();
  return 0;
}