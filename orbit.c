#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<stdio.h>
unsigned long point = 17;
unsigned long k = 1;
double screenWidth = 640;
double screenHeight = 600;
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);	
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	gluOrtho2D(0.0,(double)screenWidth,0.0,(double)screenHeight);
	

}

void Plot(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	double A,B,C,D;
	if(point % 2 !=0)
	{	
	C = screenHeight/(3*point+1);
	}
	A=screenWidth/point;
	B=10.0;
	D=10.0;
    while(point !=1)
      {
		if(point%2==0)
		{
			point = point/2;
			glBegin(GL_POINTS);
			glVertex2i( (k*A+B)  ,  (point*C+D) );
			k++;
			glEnd();
		}
		if(point % 2 !=0)
		{
			point = 3*point+1;
			glBegin(GL_POINTS);
			glVertex2i( (k*A+B) , (point*C+D) );
			k++;
			glEnd();
		}
      }
 glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("rand");
	glutDisplayFunc(Plot);
	myInit();
	glutMainLoop();
}

