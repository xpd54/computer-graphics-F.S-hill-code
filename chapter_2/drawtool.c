#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"function.h"
const screenWidth = 800;
const screenHeight = 600;

int selected=0;
GLintPoint corner[1];
void myInit(void)
{
	glClearColor(0.5,0.5,0.5,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	//glMatrixMode(GL_MODELVIEW);
	glViewport(0.0,0.0,screenWidth,screenHeight);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0f,0.1f,0.5f);
	if( selected  )
	{
		drawDot(corner[0].x,corner[0].y);
	}
	//glRecti(corner[0].x,corner[0].y,corner[1].x,corner[1].y);
	glutSwapBuffers();
}

void myMouse(int button, int state,int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		corner[0].x = x;
		corner[0].y = screenHeight - y;
		selected = 1;
	}
	if(button == GLUT_RIGHT_BUTTON)
	{
		glClearColor(0.0f,1.0f,0.0f,0.0f); // red color for the background 
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}
	glutPostRedisplay();
}

void myPassiveMotion(int x, int y)
{
	corner[0].x = x;
	corner[0].y = screenHeight - y;
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(screenWidth , screenHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Rubber rect");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMouseFunc(myMouse);
	glutPassiveMotionFunc(myPassiveMotion);
	glutMainLoop();
	return(0);
}

