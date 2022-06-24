#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Alg 1 - Using Circle Equation
static void drawCircleUsingEquation(void)
{
    int x1=0,y1=100,r=100;
    glBegin(GL_POINTS);
        while(x1<=y1){
            y1=floor(0.5+sqrt((float(r*r)-float((x1*x1)))));
            glVertex2i(x1,y1);
            glVertex2i(x1,-y1);
            glVertex2i(-x1,y1);
            glVertex2i(-x1,-y1);
            glVertex2i(y1,x1);
            glVertex2i(y1,-x1);
            glVertex2i(-y1,x1);
            glVertex2i(-y1,-x1);
            x1++;
        }
    glEnd();
    glFlush();
}
void myInit(void){
    //Making background color Red as first
    // only Red argument is 1
    //4th argument for transparency
    glClearColor(1.0f,0.0f,0.0f,1.0f);

    //Making pictur color green (in RGB mode)
    glColor3f(0.0,1.0,0.0);

    //breadth of picture boundary is 1 pixel
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Setting window dimension in x and y direction
    gluOrtho2D(-780,780,-420,420);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Assignment 3");
    myInit();
    glutDisplayFunc(drawCircleUsingEquation);
    glutMainLoop();
    return EXIT_SUCCESS;
}