#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"function.h"
#include<SOIL/SOIL.h>
const int screenWidth=800;
const int screenHeight=600;
GLdouble A,B,C,D;
void myInit(void)
{
	glClearColor(0.0,0,0.0,0);//for background
	glColor3f(1.0f,1.0f,0.0f); //for point color
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	A=screenWidth/10.0;
	B=screenWidth/2;
	C=screenHeight/2.0;
	D=screenHeight/2;
}

void myDisplay(void)
{
	GLdouble x,y,i;
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<2*M_PI;i += 0.0005)
	{
	x=10+sin(15*i);
	y=sin(i);
	drawDot(A*x+B,C*y+D);
	}
	//SOIL_save_screenshot("home/xpd54/output/plot.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
	glFlush();
	
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("parameter");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
