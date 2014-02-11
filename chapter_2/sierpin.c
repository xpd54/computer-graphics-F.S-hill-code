#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<SOIL/SOIL.h>
#include"function.h"
#include<math.h>

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);	
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,600.0);

}

void sierpinski_render(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLfloatPoint T[3] = {{10,10},{600,10},{300,600}};
	int index =rand() % 3;
	GLfloatPoint point = T[index];
	drawDot(point.x,point.y);
	int i;
	for(i=0;i<55000;i++)
	{
		index =rand() % 3;
		point.x=(point.x + T[index].x)/2;
		point.y=(point.y + T[index].y)/2;
		drawDot(point.x,point.y);
	}
	SOIL_save_screenshot("output/sierpin.bmp",SOIL_SAVE_TYPE_BMP,0,0,640,600);
	glFlush();
}


void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("sierpin");
	glutDisplayFunc(sierpinski_render);
	myInit();
	glutMainLoop();
}


