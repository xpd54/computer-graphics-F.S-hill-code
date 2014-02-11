#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);       //set white back ground color  
	glColor3f(0.0f, 0.0f, 0.0f);         //set the drawing color
	glPointSize(4.0);                   //dot is 4 by 4 pixel
	glMatrixMode(GL_PROJECTION);        
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);          //clear the screen
	glBegin(GL_POINTS);                     
	glVertex2i(100,50);                   //draw the points
	glVertex2i(160,130);
	glVertex2i(150,130);
	glVertex2i(100,150);
	glVertex2i(100,160);
	glVertex2i(100,180);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2i(20,10);
	glVertex2i(50,10);
	glVertex2i(20,80);
	glVertex2i(50,80);
	glVertex2i(20,10);
	glBegin(GL_LINES);
		glVertex2i(10,20);
		glVertex2i(40,20);
		glVertex2i(20,10);
		glVertex2i(20,40);
	
	glEnd();
	glFlush();                           //send all output to display
}
void main(int argc,char **argv)
{	
	glutInit(&argc,argv);                         //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //set display mode
	glutInitWindowSize(640,480);            //set windows size
	glutInitWindowPosition(600,550);        //set windows position on screen
	glutCreateWindow("my first attempt");   //actual function for open the windows
	glutDisplayFunc(myDisplay);           //register redraw function
	myInit();
	glutMainLoop();                   //go into a perpetual loop
}
