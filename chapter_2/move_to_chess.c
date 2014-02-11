#include<stdio.h>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
const screenWidth=560;
const screenHeight=560;
struct GLintPoint
{
	GLint x,y;
};
struct GLintPoint CP;
void myInit(void)
{
	glClearColor(1,1,1,0);
	glColor3f(1.0f,0.0f,0.0f); //for point color
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
}

void moveTO(GLint x, GLint y)  // updata the cp
{
	CP.x = x;
	CP.y = y;
}

void lineTO(GLint x, GLint y)
{
	glBegin(GL_LINES);  // DRAW THE LINE
	glVertex2i(CP.x, CP.y);
	glVertex2i(x, y);
      glEnd();
      glFlush();
      CP.x = x;  // update the current point to the previous like be can use it like moveTo(x,y); and forloop for lineTo here every time cp.x and cp.y will updated 
      CP.y = y; // update the CP
}

void chessBoard(int size,int x11,int y11)
{
	glClearColor(1,1,1,0); // white backgroud
	//glClear(GL_COLOR_BUFFER_BIT);
	int k,i,j,x1=x11,x2=size,y1=y11,y2=size;
     for(j=2;j<=9;j++)
      {
	for(i=2;i<=9;i++)
	{
	    if((i%2==0 && j%2!=0) || (i%2!=0 && j%2==0) )
	       {
			glColor3f(1,0,0);
			    glRecti(x1,y1,x2,y2);
			    x1=x1+size;
			    x2=x2+size;
		}
	     else
		{
			glColor3f(0,1,0);
			glRecti(x1,y1,x2,y2);
			x1=x1+size;
			x2=x2+size;
			
		}
	}
	x1=x11;//to reset the co-ordinate of 
	x2=size;
	y1=y1+size;
	y2=y2+size;
	

      }
		//glFlush();
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	chessBoard(70,0,0);            // try to generalise if o,o is the given point or lower co-ordinate
	glFlush();
	
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("chess");
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
}
