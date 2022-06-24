#include<windows.h>
#include<GL/GLU.h>
#include<GL/glut.h>
void display_black()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Window");
  glutDisplayFunc(display_black);
  glutMainLoop();
  return 0;
}
