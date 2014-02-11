#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const a=110351454;
const b=123;
const num=5000;

const screenWidth = 640;
const screenHeight= 600;
struct GLintPoint
{
	GLfloat x,y;
};

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);	
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,600.0);

}

void drawDot(GLint x,GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

int rnd(int n,int num)
{
	
	n=((n)*a + b)%num;
	return n;
}

void randPlot(void)
{	
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	//srand(time(NULL));
	for(i=0;i<num;i++)
	drawDot(rnd(i,screenWidth),rnd(i,screenHeight));
	glFlush();
}


void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("rand");
	glutDisplayFunc(randPlot);
	myInit();
	glutMainLoop();
}


