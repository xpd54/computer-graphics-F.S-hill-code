#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"function.h"

const num=10000;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);	
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,600.0);

}

void randPlot(void)
{	
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	srand(time(NULL));
	for(i=0;i<num;i++)
	drawDot(rand()%640,rand()%600);
	glFlush();
}


void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("rand");
	glutDisplayFunc(randPlot);
	myInit();
	glutMainLoop();
}


