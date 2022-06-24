#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Alg 3 - Using Mid Point
static void drawCircleUsingMidPoint(void)
{
    int x1=0,y1=100,r=100;
    float d=(5.0f/4.0f)-r;
    glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        glVertex2i(x1,-y1);
        glVertex2i(-x1,y1);
        glVertex2i(-x1,-y1);
        glVertex2i(y1,x1);
        glVertex2i(y1,-x1);
        glVertex2i(-y1,x1);
        glVertex2i(-y1,-x1);
        while(x1<=y1){
            x1++;
            if(d<0){
                y1=y1;
                d=d+2*x1+3;
            }else{
                y1=y1-1;
                d=d+2*(x1-y1)+4;
            }

            glVertex2i(x1,y1);
            glVertex2i(x1,-y1);
            glVertex2i(-x1,y1);
            glVertex2i(-x1,-y1);
            glVertex2i(y1,x1);
            glVertex2i(y1,-x1);
            glVertex2i(-y1,x1);
            glVertex2i(-y1,-x1);
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
    glutDisplayFunc(drawCircleUsingMidPoint);
    glutMainLoop();
    return EXIT_SUCCESS;
}