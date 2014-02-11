// used function glutCreateMenu() whith single parameter 
 //and glutAddMenuEntry(); and glutAttachMenu(whith glut button value)
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
float angle = 0.0; // for rotating the tringle
float red = 1.0,blue = 1.0, green = 1.0; // possible triangle colors
void renderScene(void)
{
	// the collback to draw the tringle 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(angle,0.0,1.0,0.0);//rotate the tringle a little more 
	glColor3f(red,green,blue); // change its color
	glBegin(GL_TRIANGLES); // drew the tringle 
	   glVertex3f(-0.5,-0.5,0.0);
	   glVertex3f(0.5,0.0,0.0);
	   glVertex3f(0.0,0.5,0.0);
	glEnd();
	angle++;
	glutSwapBuffers();
}

void processMenuEvents(int option)  //mouse choice choose color
{
	switch (option)
		{
		case RED : red = 1.0; green =0.0; blue =0.0; break;
		case GREEN : red = 0.0; green =1.0; blue =0.0; break;
		case BLUE : red = 0.0; green =0.0; blue =1.0; break;
		case WHITE : red = 1.0; green =1.0; blue =1.0; break;
		}
}

// main


void main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE |GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("menu Test");
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	// calls  to function to create the menu
	// the function called associates menu events
	// create menu and associate menu events
	glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Red",RED);
	glutAddMenuEntry("Blue",BLUE);
	glutAddMenuEntry("Green",GREEN);
	glutAddMenuEntry("White",WHITE);
	glutAttachMenu(GLUT_RIGHT_BUTTON); // ATTACH RIGHT MOUSE BUTTONTO MENU
	glutMainLoop();
	return(0);
}

