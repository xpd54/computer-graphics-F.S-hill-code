#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include"function.h"
const screenWidth=640;
const screenHeight=480;
int flag=0;

void myInit(void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
}

void myMouse(int button,int state,int x,int y)
{
	if(flag == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f,0.0f,0.0f,0.0f);
		flag = +1;
		//glFlush();
	}
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
		drawDot(x,screenHeight-y);
		glFlush();
		}
		if(button == GLUT_RIGHT_BUTTON)
		{
		glClearColor(1.0f,1.0f,0.0f,0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		}
		
		if(button == GLUT_MIDDLE_BUTTON)
		exit(-1);
	}
glutPostRedisplay();
return;
}

void myDisplay()
{
	
	glutPostRedisplay();
	return;
	
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("mouse");
	glutMouseFunc(myMouse);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glFlush();
//	glutDisplayFunc(myDisplay);
	
	myInit();
	glutMainLoop();
}
