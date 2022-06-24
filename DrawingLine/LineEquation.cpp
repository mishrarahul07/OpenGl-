#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Alg 1 - Using Line Equation
static void drawLineUsingEquation(void)
{
    int x1=50;
    int y1=50;
    int x2=400;
    int y2=275;
    glClear(GL_COLOR_BUFFER_BIT);
    float m=(float((y2-y1))/(x2-x1));
    float b=(y1-m*x1);
    glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        if(m<=1){
            for(int i=x1+1;i<=x2;i++){
                glVertex2i(i,floor(0.5f+(m*i+b)));
            }
        }else{
            for(int i=y1+1;i<=y2;i++){
                glVertex2i(floor(0.5f+((i-b)/m)),i);
            }
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
    glutDisplayFunc(drawLineUsingEquation);
    glutMainLoop();
    return EXIT_SUCCESS;
}