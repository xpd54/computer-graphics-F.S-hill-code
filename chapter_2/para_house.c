#include<math.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
const screenWidth=640;
const screenHeight=480;
struct Point
{
	int x;
	int y;
};
struct GLintPoint
{
	GLint x,y;
};

/*struct GLintPointArray
{
	const int MAX_NUM = 10000;   //here is a error
	int num;
	GLintPoint pt[MAX_NUM];
};*/

void myInit(void)
{
	glClearColor(1.0,1,1.0,0);//for background
	glColor3f(1.0f,0.0f,0.0f); //for point color
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	
}

void paraHouse(struct Point peak, GLint width, GLint height)  // to make a house with the given parameter
{
	glBegin(GL_LINE_LOOP);
	  glVertex2i(peak.x,peak.y);//draw shell of house
	  glVertex2i(peak.x + width / 2, peak.y -3 * height / 8);
	  glVertex2i(peak.x + width / 2, peak.y - height);
	  glVertex2i(peak.x - width / 2, peak.y - height);
	  glVertex2i(peak.x - width / 2, peak.y - 3* height / 8);
	glEnd();
	glBegin(GL_LINE_STRIP);  // draw chimney os house
	  glVertex2i(peak.x - 3 * width / 10, peak.y -2 * height / 8);
	  glVertex2i(peak.x - 3 * width / 10, peak.y );
	  glVertex2i(peak.x - width  / 10, peak.y);
	  glVertex2i(peak.x - width / 10 ,peak.y - height / 8);
	glEnd();
	glBegin(GL_LINE_STRIP);
	  glVertex2i(peak.x - 3 * width / 10, peak.y - height);
	  glVertex2i(peak.x - 3 * width / 10, peak.y  - 5 * height / 8);
	  glVertex2i(peak.x - width / 10, peak.y - 5 * height / 8);
	  glVertex2i(peak.x - width / 10, peak.y - height);
	glEnd();
	glBegin(GL_LINE_LOOP);
	  glVertex2i(peak.x + width / 10, peak.y - 4 * height / 8);
	  glVertex2i(peak.x + 3 * width / 10, peak.y - 4 * height / 8);
	  glVertex2i(peak.x + 3 * width / 10, peak.y - 6 * height / 8);
	  glVertex2i(peak.x +  width / 10, peak.y - 6 * height / 8);
	glEnd();
}

void Display(void)
{
	struct Point p;
	p.x=300;
	p.y=300;	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINT);
	paraHouse(p,100,100);
	glBegin(GL_LINE_LOOP);
	  glVertex2i(40,40);
	  glVertex2i(40,90);
	  glVertex2i(70,120);
	  glVertex2i(100,90);
	  glVertex2i(100,40);
	glEnd();
	glBegin(GL_LINE_STRIP);
	  glVertex2i(50,100);
	  glVertex2i(50,120);
	  glVertex2i(60,120);
	  glVertex2i(60,110);
	glEnd();
	glBegin(GL_LINE_STRIP);
	  glVertex2i(50,40);
	  glVertex2i(50,70);
	  glVertex2i(60,70);
	  glVertex2i(60,40);
	glEnd();
	glBegin(GL_LINE_LOOP);
	  glVertex2i(70,65);
	  glVertex2i(70,75);
	  glVertex2i(80,75);
	  glVertex2i(80,65);
	glEnd();
	glFlush();

}



void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("HOUSE");
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
}
