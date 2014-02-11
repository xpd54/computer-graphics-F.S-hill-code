#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"
#define N 15
#include<time.h>
const screenWidth =  700;
const screenHeight = 700;
const dev = N/2;
int flag=0,flag2=1;
struct GLfloatPoint point[N],point2[N];
void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	
}

float rosette(int n,float radius)
{ 
	float phi=(2* M_PI)/n;
	int count,i=0,j=0;
	if(flag2==1)
	{
		for(count=0;count<n;count++)
		{
			point[count].x=radius*cos(phi * count+34.03);
			point[count].y=radius*sin(phi * count+34.03);
		}
		flag2++;
	}
		while(j<n)
		{
			if(i*j%2==0)
			glColor3f(1.0f,1.0f,0.0f);
			if((i+j)%2==0)
			glColor3f(1.0f,0.0f,1.0f);
			moveTo(point[j].x,point[j].y);
			lineTo(point[j+dev].x,point[j+dev].y);
			j=j+dev;
			if(j==n-1)
			{
				for(count=0;count<n;count++)
				{
					point2[count]=point[j];
					j++;
					if(j==n)
					j=0;
				}
				for(count=0;count<n;count++)
				{
					point[count]=point2[count];
				}
				
				while(flag<1)
				{
				rosette(n,radius);
				flag++;
				}
			}
			
		}
	//float pi=(1+sqrt(5))/2;
	//radius=radius/(1+pi*pi);
	return radius;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,screenWidth,screenHeight);
	rosette(N,0.75);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutInitWindowSize(screenWidth,screenHeight);
	glutCreateWindow("rosette");
	glutDisplayFunc(render);
	myInit();
	glutMainLoop();
}
