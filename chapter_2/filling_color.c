#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
const screenWidth=640;
const screenHeight=480;
void myInit(void)
{
	glClearColor(1.0,1,1.0,0);//for background
	glColor3f(1.0f,0.0f,0.0f); //for point color
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_POLYGON);
	  glVertex2i(40,40);
	  glVertex2i(40,90);
	  glVertex2i(70,120);
	  glVertex2i(100,90);
	  glVertex2i(100,40);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(70,120);
	glVertex2f(120,140);
	glVertex2f(20,140);
	glEnd();
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("filling_color");
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
}
