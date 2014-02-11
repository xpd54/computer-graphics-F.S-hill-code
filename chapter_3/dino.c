#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<SOIL/SOIL.h>
#include"function.h"
const screenWidth = 600;
const screenHeight = 480;
void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0f,0.0f,1.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,screenWidth,0,screenHeight);
}

/*void drawPolyLineFile(char *fileName)
{
	FILE *inStream;
	inStream=fopen(fileName,"r");
	glClear(GL_COLOR_BUFFER_BIT);
	int numpolys,numLines,x,y;
	fscanf(inStream ,"%d",&numpolys);      // read the number of polylines
	int j,i;
	for(j=0; j< numpolys;j++)   //total number of polylines in the file
	{
		fscanf(inStream,"%d",&numLines);     // number of point in the polylines    
		glBegin(GL_LINE_STRIP); 
		for(i=0;i<numLines; i++)        
		{
			fscanf(inStream,"%d", &x);
			fscanf(inStream,"%d", &y);
			glVertex2i(x,y);

		}
		glEnd();	
	}
	
	glFlush();
	fclose(inStream);
}*/
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolylineFile("dino.dat");
	glFlush();
	SOIL_save_screenshot("/home/xpd54/personal/mywork/cg/output/dino.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("dino");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
