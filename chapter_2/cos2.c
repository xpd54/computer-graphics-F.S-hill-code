#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
const screenWidth=640;
const screenHeight=480;
GLdouble A,B,C,D;
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);       //set white back ground color  
	glColor3f(0.0, 0.0, 0.0);         //set the drawing color
	glPointSize(1.0);                   //dot is 4 by 4 pixel
	glMatrixMode(GL_PROJECTION);        
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	A=screenWidth/(2*M_PI);
	B=0.0;
	C=screenHeight/2;
	D=screenHeight/2;
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	//GLdouble i,j,l,m;
	GLdouble x,func;
	for(x=0;x<2*M_PI;x+=0.002)
	{
		func=cos(x);
		glVertex2d(x*A+B,func*C+D);
	}
	glEnd();
	glFlush();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("log plot");
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
}
