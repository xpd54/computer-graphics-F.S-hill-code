//basic input and output in opengl for polygon
#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<math.h>
#include<SOIL/SOIL.h>
#include"function.h"
#define TRI 1
#define REC 2
#define HEX 3
#define CIR 4
#define EXI 5
const screenWidth=1024;
const screenHeight=700;
int flag=0,vertex,edge=2,count=0,count2,distance,radius;
struct GLintPoint corner[4];
int tri=0,rec=0,hex=0,cir=0;
void myInit(void)
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
}

void glCircle3i(int x, int y, int radius) 
{
	float angle;
	glColor3f(0.0f, 1.0f, 0.0f);
	glLineWidth(1.0f);
	glBegin(GL_POLYGON);
	int i;
	for(i= 0; i < 100; i++) 
	{
		angle = i*2*M_PI/100;
		if(i%2 == 0)
		glColor3f(0.0f, 0.0f, 1.0f);
		else
		glColor3f(1.0f, 1.0f, 0.0f);
	        glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
	}
	glEnd();
} 

void glHexagon(int x,int y,int radius)
{
	float angle;
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glColor3f(0.0f, 1.0f, 0.0f);
	glLineWidth(1.0f);
	glBegin(GL_POLYGON);
	int i;
	for(i= 0; i < 7; i++) 
	{
		angle = i*2*M_PI/6;
		if(i%2 == 0)
		glColor3f(1.0f, 0.0f, 0.0f);
		else
		glColor3f(0.0f, 1.0f, 0.0f);
	        glVertex2f(x + (cos(angle) * radius), y + (sin(angle) * radius));
	}
	glEnd();
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
}

void myMouse(int button,int state,int x,int y)
{
	
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			
			flag=0;
			if(flag==0);
			{
				corner[vertex].x=x;
				corner[vertex].y=screenHeight-y;
				vertex++;
			}
			
			glFlush();
		}
		
		if(button == GLUT_MIDDLE_BUTTON)
		{
			while(count=!2)
			{
				corner[count].x=0;
				corner[count].y=0;
				count++;
			}
			vertex=0;
			glutPostRedisplay();
			
		}
	}
return;
}

void processMenuEvents(int option)  //mouse choice choose
{
	switch (option)
		{
		case TRI:
		tri=1;
		break;
		case REC :
		rec=1;
		break;
		case HEX :
		hex=1;
		break;
		case CIR :
		cir=1;
		break;
		case EXI :
		exit(-1);
		break;
		}
}

void myDisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	float hori,ver,angle=0;
	double angleInc = 2*(M_PI/6.0);
	if(rec==1)
	{
	glRecti(corner[0].x,corner[0].y,corner[1].x,corner[1].y);
	SOIL_save_screenshot("output/rect.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
	rec=0;
	}
	if(tri==1)
	{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(corner[0].x,corner[0].y);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(corner[1].x,corner[1].y);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f(corner[2].x,corner[2].y);
	glEnd();
	SOIL_save_screenshot("output/triangle.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
	tri=0;
	}
	if(hex==1)
	{
		radius=(int)sqrt(pow((corner[0].x - corner[1].x),2) + pow((corner[0].y - corner[1].y),2) );
		glHexagon(corner[0].x,corner[0].y,radius);
		SOIL_save_screenshot("output/hexagon.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
		hex=0;
	}
	if(cir==1)
	{
		radius=(int)sqrt(pow((corner[0].x - corner[1].x),2) + pow((corner[0].y - corner[1].y),2) );
		glCircle3i(corner[0].x,corner[0].y,radius);
		SOIL_save_screenshot("output/circle.bmp",SOIL_SAVE_TYPE_BMP,0,0,screenWidth,screenHeight);
		cir=0;
		
	}
	glFlush();
	
}
void manu(void)
{
	glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Triangle",TRI);
	glutAddMenuEntry("Rectangle",REC);
	glutAddMenuEntry("Hexagon",HEX);
	glutAddMenuEntry("Circle",CIR);
	glutAddMenuEntry("Exit",EXI);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("chess");
	glutMouseFunc(myMouse);
	glutDisplayFunc(myDisplay);
	manu();
	myInit();
	glutMainLoop();
}
