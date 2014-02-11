#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include"function.h"
const screenWidth=1024;
const screenHeight=700;
const M=55;
const L=4;
int flag=0;
struct GLintPoint start[1];

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
		start[0].x = x;
		start[0].y = y;
		glFlush();
		}
		if(button == GLUT_RIGHT_BUTTON)
		{
		glClearColor(1.0f,1.0f,0.0f,0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.0f,0.0f,0.0f);
		glFlush();
		}
		
		if(button == GLUT_MIDDLE_BUTTON)
		{
		SOIL_save_screenshot("output/test.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
		exit(-1);
		}
	}
glutPostRedisplay();
return;
}

void myDisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	unsigned char image[screenWidth*screenHeight*3];
	struct GLintPoint q,p;
	int i;
	p.x=start[0].x;
	p.y=start[0].y;
	//drawDot(p.x,p.y);
	for(i=0;i<5000;i++)
	{
		q.x = M*(1+2*L) - p.y + abs( p.x - L * M);
		q.y = p.x;
		drawDot(q.x,q.y);
		p.x=q.x;
		p.y=q.y;
	}
	glFlush();
	
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("mouse");
	glutMouseFunc(myMouse);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glFlush();
	glutDisplayFunc(myDisplay);
	
	myInit();
	glutMainLoop();
}
