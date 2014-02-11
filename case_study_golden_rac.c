#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"function.h"
#include<SOIL/SOIL.h>
const int screenWidth=600;
const int screenHeight=400;
GLdouble A,B,C,D;
void myInit(void)
{
	glClearColor(0.0,0,0.0,0);//for background
	glColor3f(1.0f,1.0f,0.0f); //for point color
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
}



void goldenRactangle(struct GLfloatPoint origin,struct GLfloatPoint vertex)
{
	glRecti(origin.x,origin.y,vertex.x,vertex.y);
	
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	struct GLfloatPoint origin,prepoint,A,B,C,D;
	double pi,width,height,x,y;
	pi = (1+sqrt(5))/2;
	prepoint.x=prepoint.y=10;
	width=600;
	height=(600/pi);
	A.x=prepoint.x;
	A.y=prepoint.y;
	B.x=A.x;
	B.y=height;
	C.x=width;
	C.y=height;
	D.x=width;
	D.y=A.y;
	glColor3f(1.0f,1.0f,0.0f);
	goldenRactangle(A,C);
	glColor3f(1.0f,0.0f,0.0f);
	drawLine(A.x=B.x+width/pi,A.y=B.y,D.x=A.x+width/pi,D.y=A.y);
	B.x=C.x;
	B.y=C.y;
	height=B.x-A.x;
	width=D.y-A.y;
	C.x=
	glFlush();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(100,150);
	glutCreateWindow("golden ractangle");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
