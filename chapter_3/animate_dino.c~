#include<stdio.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include"function.h"
const screenWidth =700;
const screenHeight=700;
volatile center_left=0.0,center_bottom=0.0;
int a=10,d=10,w=10,s=10;
int width=350;
int height=350;

void myInit()
{
	glClearColor(1.0,1.0,0.0,0.0);         
	glColor3f(0.0, 0.0, 0.0);        
	glPointSize(5.0);                   
	setWindow(0.0,screenWidth,0.0,screenHeight);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	drawPolylineFile("dino.dat");
	glutSwapBuffers();
	//glFlush();
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'a':
		setViewport(center_left -=a,width-=a,center_bottom,height);
		break;
		case 'd':
		setViewport(center_left+=d,width+=d,center_bottom,height);
		break;
		case 'w':
		setViewport(center_left,width,center_bottom+=w,height+=w);
		break;
		case 's':
		setViewport(center_left,width,center_bottom-=s,height-=s);
		break;
		case 'e':
		exit(-1);
		default:
		break;
	}
	glutPostRedisplay();
}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,100);
	glutCreateWindow("ANIMATE");
	glutDisplayFunc(myDisplay);
	myInit();
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
