#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"
const screenWidth = 700;
const screenHeight = 700;

void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0, 0.0, 0.0); 
	glPointSize(2.0);
	setWindow(0.0,screenWidth,0.0,screenHeight);
	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	struct GLintPoint center;
	center.x =350;
	center.y =350;
	int w=200,h=100;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	drawEllipse(w,h,center);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	drawCircle(center.x,center.y,(w-10)/2);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	drawEllipse(((w-10)/2)-10,(w-10)/4,center);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	drawCircle(center.x,center.y,((w-10)/4)-10);
	
	
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
