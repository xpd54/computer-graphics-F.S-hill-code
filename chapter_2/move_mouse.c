// that programm is denote how to handal a mouse movement
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
#include"function.h"
const screenWidth=640;
const screenHeight=480;
int selected = 0;
struct GLintPoint corner[2];
void myInit(void)
{
	glClearColor(0,0,0,0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	glMatrixMode(GL_MODELVIEW );
	glViewport(0,0,screenWidth,screenHeight);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0f,0.1f,0.5f);
	if( selected  )
	{
		glBegin(GL_QUADS);
		glVertex2i(corner[0].x,corner[0].y);
		glVertex2i(corner[0].x,corner[1].y);
		glVertex2i(corner[1].x,corner[1].y);
		glVertex2i(corner[1].x,corner[0].y);
	glEnd();
	}
	glutSwapBuffers();
}

void myMouse(int button,int state, int x,int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		corner[0].x =x;
		corner[0].y = screenHeight - y;
		selected = 1;
	}
	glutPostRedisplay(); //every time it force to glut to call mydisplay()
	if(button == GLUT_RIGHT_BUTTON)
		{
		glClearColor(0.0f,1.0f,0.0f,0.0f); // red color for the background 
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
		}
	if(button == GLUT_MIDDLE_BUTTON)
	{
		glClearColor(0.0f,1.0f,1.0f,0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush();
	}

}

void myPassiveMotion(int x,int y)
{
	corner[1].x = x;
	corner[1].y = screenHeight -y;
	glutPostRedisplay();  // it call my display again and agian
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
