#include<stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include <math.h>
#include<time.h>
int screenWidth = 500;
int screenHeight = 500;
void myinit()
{
	glClearColor (1.0, 1.0, 0.0, 1.0);	
	glColor3f (0.0, 0.0, 1.0);                  
	glPointSize (3.0);                          
	glViewport (0.0, 0.0, 500.0, 500.0);        
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
	glMatrixMode (GL_MODELVIEW);

}
void hexswirl()
{
	double angle;                       
	double angleInc = 2*3.14159265/6.0; 
	double inc = 5.0/100;               
	double radius = 5.0/100.0;        
	glClear (GL_COLOR_BUFFER_BIT);
	int j,k;
	for (j = 0; j <= 100; j++)
	{

		angle = j* (3.14159265/180.0);
		glBegin (GL_LINE_STRIP);
			for (k=0; k <= 6; k++)
			{
				angle += angleInc;
				glVertex2d(radius * cos(angle), radius *sin(angle));

			}
		glEnd();
		radius += inc;
	}
	glutSwapBuffers();

	glFlush();
}

void zoomIn(unsigned char key, int x, int y)
{
	float cx = 0.0, cy = 0.0;      
	float h=1.2, w = 1.2;           
	int NumFrames = 10;             

	
	int frame,i;
	for (frame = 0; frame < NumFrames; frame++)
	{
		
		w *= 0.9;
		h *= 0.9; 

	
		gluOrtho2D (cx - w, cx + w, cy - h, cy + h);
		hexswirl();
		for (i = 0; i <= 200000000; i++);
		
	}

}


int main(int argc, char** argv)
{

	
	glutInit(&argc, argv);	
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hexagon Swirl");
	glutDisplayFunc(hexswirl);
	glutKeyboardFunc(zoomIn);
	myinit();
	glutMainLoop();
	return 0;
}

