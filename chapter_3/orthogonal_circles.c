#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include<time.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;

void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);       
	glColor3f(0.0, 0.0, 0.0);         
	glPointSize(5.0);                   
	setWindow(0.0,screenWidth,0.0,screenHeight);	
	
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	float a=100,b=-100,m=1,n=1;
	struct GLfloatPoint center;
	center.x=350.0;
	center.y=350.0;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,350);
	glVertex2f(700,350);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(350,0.0);
	glVertex2f(350,700);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	for(m=1;m<2;m+=0.2)
	{
		glBegin(GL_LINE_STRIP);
		drawCircle(center.x,center.y+a,m*a);
		glBegin(GL_LINE_STRIP);
		drawCircle(center.y,center.y+b,m*a);
	}
	for(n=1;n<2;n+=0.2)
	{
		glBegin(GL_LINE_STRIP);
		drawCircle(center.x+a*n,center.y,a*sqrt(n*n-1));
		glBegin(GL_LINE_STRIP);
		drawCircle(center.x+b*n,center.y,a*sqrt(n*n-1));
	}
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("orthogonal");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
