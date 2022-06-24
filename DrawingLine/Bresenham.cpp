#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Alg 3 - Using Brehsenham
static void drawLineUsingBresenham(void)
{
    int x1=50;
    int y1=50;
    int x2=400;
    int y2=275;
    glClear(GL_COLOR_BUFFER_BIT);
    int dx=x2-x1;
    int dy=y2-y1;
    float m=(float(dy)/dx);
    glBegin(GL_POINTS);
        glVertex2i(x1,y1);
        if(m<=1){
            int decisionParameter=(2*dy)-dx;
            int prev=y1;
            for(int i=x1+1;i<=x2;i++){
                if(decisionParameter>=0){
                    decisionParameter=decisionParameter+((dy-dx)>>1);
                    prev=prev+1;
                }else{
                    decisionParameter=decisionParameter+((dy)>>1);
                }
                glVertex2i(i,prev-1);
            }
        }else{

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
    glutDisplayFunc(drawLineUsingBresenham);
    glutMainLoop();
    return EXIT_SUCCESS;
}