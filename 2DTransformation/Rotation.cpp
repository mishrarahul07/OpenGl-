#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;

static void rotation(void){
    int x1=30,y1=30;
    int x2=110,y2=30;
    int x3=70,y3=100;
    double pi=3.14159265358979323846;
    double theta=pi/4.0;

    glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
        glVertex2i(x3,y3);
        glVertex2i(x1,y1);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2i(x1*cos(theta)-y1*sin(theta),x1*sin(theta)+y1*cos(theta));
        glVertex2i(x2*cos(theta)-y2*sin(theta),x2*sin(theta)+y2*cos(theta));
        glVertex2i(x2*cos(theta)-y2*sin(theta),x2*sin(theta)+y2*cos(theta));
        glVertex2i(x3*cos(theta)-y3*sin(theta),x3*sin(theta)+y3*cos(theta));
        glVertex2i(x3*cos(theta)-y3*sin(theta),x3*sin(theta)+y3*cos(theta));
        glVertex2i(x1*cos(theta)-y1*sin(theta),x1*sin(theta)+y1*cos(theta));
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
    glutCreateWindow("Assignment 5");
    myInit();
    glutDisplayFunc(rotation);
    glutMainLoop();
    return EXIT_SUCCESS;
}