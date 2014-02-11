#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"

const screenWidth =  700;
const screenHeight = 700;
const dev = 2;
void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	
}

float rosette(int N,float radius)
{ 
	struct GLfloatPoint point[N];
	float phi=(2* M_PI)/N;
	int count,i,j=0,flag=1;
	for(count=0;count<N;count++)
	{
		point[count].x=radius*cos(phi * count+34.03);
		point[count].y=radius*sin(phi * count+34.03);
	}
		while(j<N)
		{
			if(i*j%2==0)
			glColor3f(1.0f,1.0f,0.0f);
			if((i+j)%2==0)
			glColor3f(1.0f,0.0f,1.0f);
			moveTo(point[j].x,point[j].y);
			lineTo(point[j+dev].x,point[j+dev].y);
			j=j+dev;
			if(j==N-1)
			{
				do
				{
					
					if(flag==1)
					{
						flag++;
						moveTo(point[j].x,point[j].y);
						lineTo(point[dev-1].x,point[dev-1].y);
						j=dev-1;
					}
					else
					{
						moveTo(point[j].x,point[j].y);
						lineTo(point[j+dev].x,point[j+dev].y);
						j=j+dev;
					}
					if(j==N-dev)
					{
						moveTo(point[j].x,point[j].y);
						lineTo(point[0].x,point[0].y);
					}
				}
				while(j<N);
			}
			
		}
	float pi=(1+sqrt(5))/2;
	radius=radius/(1+pi*pi);
	return radius;
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,screenWidth,screenHeight);
	rosette(9,0.75);
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
