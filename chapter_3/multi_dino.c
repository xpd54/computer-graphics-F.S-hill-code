#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<SOIL/SOIL.h>
#include"function.h"

const screenWidth = 640;
const screenHeight = 440;

void myInit()
{
	glClearColor(0.0,0.0,1.0,0.0); // black background
	glColor3f(1.0f,1.0f,0.0f);
	glPointSize(1.0);
}

/*void setWindow(GLdouble left,GLdouble right,GLdouble bottom,GLdouble top)
{
	//define our own function to specify the window as explained 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}

void setViewport(GLint left,GLint right,GLint bottom,GLint top)
{	
	// define our own function to specify the window as explained--
	glViewport(left,bottom,right-left,top - bottom);
}*/

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	setWindow(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);    // set a fixed window 
	int i,j;
	for(i=0;i <10;i++)
	{
		for(j = 0;j < 10;j++)
		{
		glViewport( i*64, j*44, 64, 44 ) ; 
		drawPolylineFile( "dino.dat" ) ;
		}
	}
	glFlush();
	SOIL_save_screenshot("/home/xpd54/personal/mywork/cg/output/muti_dino.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
}

void main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("muti_dino");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
