#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include<time.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;
const number_of_tilli=8;
void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);       
	glColor3f(0.0, 0.0, 0.0);         
	glPointSize(5.0);                   
	setWindow(0.0,screenWidth,0.0,screenHeight);
	//setWindow(-2*M_PI,2*M_PI,-2*M_PI,2*M_PI);
	
}

void tilli1()
{
	/*glBegin(GL_LINE_LOOP);
	glVertex2f(0.0,0.0);
	glVertex2f(screenWidth,0.0);
	glVertex2f(screenWidth,screenHeight);
	glVertex2f(0.0,screenWidth);
	glEnd();*/
	glColor3f(1.0, 0.0, 0.0); 
	drawArc(0.0,0.0,0.0,M_PI/2,screenWidth/2);
	glColor3f(0.0, 0.0, 1.0); 
	drawArc(screenWidth,screenHeight,M_PI,3*M_PI/2,screenWidth/2);
}

void tilli2()
{
	/*glBegin(GL_LINE_LOOP);
	glVertex2f(0.0,0.0);
	glVertex2f(screenWidth,0.0);
	glVertex2f(screenWidth,screenHeight);
	glVertex2f(0.0,screenWidth);
	glEnd();*/
	glColor3f(0.0, 1.0, 0.0); 
	drawArc(screenWidth,0.0,M_PI/2,M_PI,screenWidth/2);
	glColor3f(1.0, 1.0, 0.0); 
	drawArc(0.0,screenHeight,3*M_PI/2,2*M_PI,screenWidth/2);
}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int i,j;
	for(i=0;i<screenHeight;i+=screenHeight/number_of_tilli)
	for(j=0;j<screenWidth;j+=screenWidth/number_of_tilli)
	{
		int flag=random();
		setViewport(j,j+screenWidth/number_of_tilli,i,i+screenHeight/number_of_tilli);
		if(flag%2==0)
		tilli2();
		else
		tilli1();
	}
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("tillings");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
