#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
void myInit()
{
	glClearColor(1,1,1,0);
	glColor3f(1.0f,0.0f,0.0f);//point color
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
	
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINT);
	glBegin(GL_LINE_STRIP);
	 glVertex2i(20,10);
	 glVertex2i(50,10);
	 glVertex2i(20,80);
	 glVertex2i(50,80);
    glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex2i(80,200);
		glVertex2i(50,100);
		glVertex2i(130,150);
		glVertex2i(30,150);
		glVertex2i(110,100);
		glVertex2i(80,200);
		
	glEnd();
		
    glFlush();

}

void drawLine(GLint x1,GLint y1,GLint x2,GLint y2)   // to make a function for draw a line as run time function
{
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
    glEnd();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);    // to initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //set window size
	glutInitWindowPosition(100,150);  // set the window size
	glutCreateWindow("Dot plot of a Function");
	glutDisplayFunc(myDisplay);  // register redraw function 
	myInit();
	glutMainLoop();    // go into a perpetual loop
}
