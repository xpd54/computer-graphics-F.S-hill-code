#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include"function.h"
 
const screenWidth=700;
const screenHeight=700;

void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0f,1.0f,0.0f);
	glPointSize(2.0);
}
void hexagon(float radius,float angle)
{
	struct GLfloatPoint point[6];
	int count,i,j;
	float phi=(2*M_PI)/6;
	for(count=0;count<6;count++)
	{
		point[count].x=radius*cos((phi * count)+angle);
		point[count].y=radius*sin((phi * count)+angle);
	}
	float mid_x,mid_y,m=abs((point[3].y-point[1].y)/(point[3].x-point[1].x));
	float m2=-1/m,midx,midy;
	mid_y=((abs(pow(m,2)*point[2].y+2*m*point[2].x+2*point[1].x-2*point[1].y*m-point[2].y)))/(1+pow(m,2));
	mid_x=m*abs((point[2].y+point[2].x/m-mid_y));
	midx=(point[3].x+point[1].x)/2;
	midy=(point[3].y+point[1].y)/2;
	point[2].x=2*midx-point[2].x;
	point[2].y=2*midy-point[2].y;
	for(count=0;count<6;count++)
	{
		moveTo(point[count].x,point[count].y);
		if(count+1!=6)
		lineTo(point[count+1].x,point[count+1].y);
		else
		lineTo(point[0].x,point[0].y);
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	setViewport(0,screenWidth/2,0,screenHeight/2);
	hexagon(1,M_PI/2);
	setViewport(screenWidth/2,screenWidth,0.0,screenHeight/2);
	hexagon(1,3*M_PI+M_PI/6);
	setViewport(screenWidth/4,screenWidth*3/4,screenHeight/2-45,screenHeight-45);
	hexagon(1,-M_PI/6);
	glFlush();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	setWindow(0.0,screenWidth,0.0,screenHeight);
	glutInitWindowSize(screenWidth,screenHeight);
	glutCreateWindow("logo");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}

