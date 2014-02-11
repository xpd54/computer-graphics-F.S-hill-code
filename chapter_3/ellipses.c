#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;
void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);       //set white back ground color  
	glColor3f(0.0, 0.0, 0.0);         //set the drawing color
	glPointSize(2.0);                   //dot is 4 by 4 pixel
	setWindow(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	double i;
	glBegin(GL_LINE_LOOP);
	//setViewport(0.0,screenWidth/400,0.0,screenHeight/400);
	for(i=0;i<5;i++)
	glVertex2f(200+2*cos(2*M_PI*i/9),200+1*sin(2*M_PI*i/9));
	glEnd();
}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("ellipses");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}
