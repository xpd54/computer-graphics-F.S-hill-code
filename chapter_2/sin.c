#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
const screenWidth=640;
const screenHeight=480;
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);       //set white back ground color  
	glColor3f(0.0, 0.0, 0.0);         //set the drawing color
	glPointSize(1.0);                   //dot is 4 by 4 pixel
	glMatrixMode(GL_PROJECTION);        
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	GLdouble i,j,l,m;
	//for (l=0;l<screenWidth;l+=0.05)
//{
	for(i=0.0;i<4*M_PI;i+=0.005)
	{
		j=sin(i);
		glVertex2d(i*screenWidth/(4*M_PI)+l,j*screenHeight/4+screenHeight/2);
	}
	for(i=0.0;i<4*M_PI;i+=0.005)
	{
		j=-sin(i);
		glVertex2d((i*screenWidth/(4*M_PI)+l),j*screenHeight/4+screenHeight/2);
		glVertex2d(i*screenWidth/(4*M_PI),screenHeight/2);
	}
//}
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
