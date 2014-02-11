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
	glClearColor(0.0,0,0.0,0.0);//for background
	glColor3f(1.0f,1.0f,0.0f); //for point color
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	A=screenWidth/(300);
	B=0.0;//screenWidth;
	C=screenHeight/236.0;
	D=screenHeight/2;
}

void myDisplay(void)
{
	GLdouble x1,y1,x2,y2,i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for(i=0;i<300;i += 3)
	{
	y1=300-100*cos((2*M_PI*i)/100)+30*cos((4*M_PI*i)/100)+6*cos((6*M_PI*i)/100);
	glVertex2d(A*i+B,C*y1+D);
	}
	glEnd();
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
