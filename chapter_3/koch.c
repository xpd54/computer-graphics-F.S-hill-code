#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include"function.h"
const screenWidth =  700;
const screenHeight = 700;


struct pointSet
{
	struct GLfloatPoint p1,p2,p3,p4,p5;
};
int dotForDraw(struct GLfloatPoint,struct GLfloatPoint);
void draw_point(struct pointSet);
void myInit();
void display(void);

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutInitWindowSize(screenWidth,screenHeight);
	glutCreateWindow("koch curve");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}

void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);       //set white back ground color  
	glColor3f(0.0, 0.0, 0.0);         //set the drawing color
	glPointSize(2.0);                   //dot is 4 by 4 pixel
	setWindow(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	struct GLfloatPoint point1,point2;
	setViewport(0.0,screenWidth,0.0,screenHeight);
	point1.x=0;
	point1.y=200;
	point2.x=screenWidth;
	point2.y=200;
	dotForDraw(point1,point2);
	glFlush();
}

void draw_point(struct pointSet point)
{
	dotForDraw(point.p1,point.p3);
	dotForDraw(point.p3,point.p5);
	dotForDraw(point.p5,point.p4);
	dotForDraw(point.p4,point.p2);
}


int dotForDraw(struct GLfloatPoint point1,struct GLfloatPoint point2)
{
	struct GLfloatPoint p1,p2,p3,p4,p5;
	struct pointSet point;
	float m,dis,angle,angle2;
	dis=sqrt(pow((p2.y-p1.y),2)+pow((p2.x-p1.x),2));
	m=(p2.y-p1.y)/(p2.x-p1.x);
	angle=atan(m);
	angle2=atan(-1/m);
	p1=point1;
	p2=point2;
	p3.x=p1.x+(p2.x-p1.x)/3;
	p3.y=p1.y+(p2.y-p1.y)/3;
	p4.x=(p3.x+p2.x)/2;
	p4.y=(p3.y+p2.y)/2;
	p5.x=p3.x+(p4.x-p3.x)*cos(angle+M_PI/3);
	p5.y=p3.y+(p4.x-p3.x)*sin(angle+M_PI/3);
	moveToPoint(p1);
	lineToPoint(p3);
	moveToPoint(p3);
	lineToPoint(p5);
	moveToPoint(p5);
	lineToPoint(p4);
	moveToPoint(p4);
	lineToPoint(p2);
	point.p1=p1;
	point.p2=p2;
	point.p3=p3;
	point.p4=p4;
	point.p5=p5;
	if(sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2))>1)
	draw_point(point);
	else
	return 1;
	
}

