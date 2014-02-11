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
	glBegin(GL_LINE_LOOP);
	  glVertex2i(40,40);
	  glVertex2i(40,90);
	  glVertex2i(70,120);
	  glVertex2i(100,90);
	  glVertex2i(100,40);
	glEnd();
	glBegin(GL_LINE_STRIP);
	  glVertex2i(50,100);
	  glVertex2i(50,120);
	  glVertex2i(60,120);
	  glVertex2i(60,110);
	glEnd();
	glBegin(GL_LINE_STRIP);
	  glVertex2i(50,40);
	  glVertex2i(50,70);
	  glVertex2i(60,70);
	  glVertex2i(60,40);
	glEnd();
	glBegin(GL_LINE_LOOP);
	  glVertex2i(70,65);
	  glVertex2i(70,75);
	  glVertex2i(80,75);
	  glVertex2i(80,65);
	glEnd();
	glFlush();

}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("HOUSE");
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
}
