#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>


# define PI  3.14159265358979323846
GLfloat win = 0.0f;

void AirportView(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	// Green Ground
	glBegin(GL_QUADS);
	glColor3ub(100, 116, 72);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 0);
	glVertex2f(-1, 0);
	glEnd();

	// Start Tree-1
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(-0.5, -0.9);
	glVertex2f(-0.45, -0.9);
	glVertex2f(-0.45, -0.4);
	glVertex2f(-0.5, -0.4);
	glEnd();

	int i_tree;

	//-------------Start Tree-1 circle-1 ----------
	GLfloat x = -0.55f; GLfloat y = -0.4f; GLfloat radius = .09f;
	int triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------End Tree-1 circle-1----------

	//-------------Start Tree-1 circle-2----------
	 x = -0.4f;  y = -0.4f;  radius = .09f;
	 triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------end Tree-1 circle-2----------

	//-------------Start Tree-1 circle-3----------
	x = -0.45f;  y = -0.3f;  radius = .09f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	//-------------End Tree-1 circle-3----------
	glEnd();
	// End Tree-1


    //Tree-2 Scale and Translate
	glScalef(0.7, 0.8, 0);
	glTranslatef(0.1, 0.1, 0);


	// Start Tree-2
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(-0.5, -0.9);
	glVertex2f(-0.45, -0.9);
	glVertex2f(-0.45, -0.4);
	glVertex2f(-0.5, -0.4);
	glEnd();

	//-------------Start Tree-2 circle-1 ----------
	 x = -0.55f;  y = -0.4f;  radius = .09f;
	 triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------End Tree-2 circle-1----------

	//-------------Start Tree-2 circle-2----------
	x = -0.4f;  y = -0.4f;  radius = .09f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------end Tree-2 circle-2----------

	//-------------Start Tree-2 circle-3----------
	x = -0.45f;  y = -0.3f;  radius = .09f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	//-------------End Tree-2 circle-3----------
	glEnd();
	// End Tree-2

	// Come Back real Position
	glLoadIdentity();


	//Tree-3 Scale and Translate
	glScalef(0.4, 0.5, 0);
	glTranslatef(0.2, 0.2, 0);


	// Start Tree-3
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(-0.5, -0.9);
	glVertex2f(-0.45, -0.9);
	glVertex2f(-0.45, -0.4);
	glVertex2f(-0.5, -0.4);
	glEnd();

	//-------------Start Tree-3 circle-1 ----------
	x = -0.55f;  y = -0.4f;  radius = .09f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------End Tree-3 circle-1----------

	//-------------Start Tree-3 circle-2----------
	x = -0.4f;  y = -0.4f;  radius = .09f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------end Tree-3 circle-2----------

	//-------------Start Tree-3 circle-3----------
	x = -0.45f;  y = -0.3f;  radius = .09f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	//-------------End Tree-3 circle-3----------
	
	// End Tree-3

	// Come Back real Position
	glLoadIdentity();

	//================Start Windmill====================

	// Start Windmill-1
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.9);
	glVertex2f(0.48, -0.9);
	glVertex2f(0.48, -0.4);
	glVertex2f(0.5, -0.4);
	glEnd();

	
	glPushMatrix();
	glTranslatef(0.49f, -0.4f, 0);
	glRotatef(win, 0, 0, 1);
	glTranslatef(-0.49f, 0.4f, 0);
	//-------------Start Windmill-1 circle----------
	
	x = 0.49f;  y = -0.4f;  radius = .04f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	// Come Back real Position
	
	


	// Triangles-1
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.49, -0.38);
	glVertex2d(0.3, -0.42);
	glVertex2f(0.49, -0.43);
	glEnd();

	// Triangles-2
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.38);
	glVertex2d(0.65, -0.5);
	glVertex2f(0.5, -0.42);
	glEnd();

	// Triangles-3
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.38);
	glVertex2d(0.55, -0.2);
	glVertex2f(0.52, -0.38);
	glEnd();

	glLoadIdentity();
	glPopMatrix();
	win += 0.1;

	// End Windmill-1

	//Tree-3 Scale and Translate
	glScalef(0.4, 0.5, 0);
	glTranslatef(0.2, 0.2, 0);

	// Start Windmill-2
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.9);
	glVertex2f(0.48, -0.9);
	glVertex2f(0.48, -0.4);
	glVertex2f(0.5, -0.4);
	glEnd();


	glPushMatrix();
	glTranslatef(0.49f, -0.4f, 0);
	glRotatef(win, 0, 0, 1);
	glTranslatef(-0.49f, 0.4f, 0);
	//-------------Start Windmill-1 circle----------

	x = 0.49f;  y = -0.4f;  radius = .04f;
	triangleAmount = 20; //# of triangles used to draw circle

						 //GLfloat radius = 0.8f; //radius
	twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i_tree = 0; i_tree <= triangleAmount; i_tree++) {
		glVertex2f(
			x + (radius * cos(i_tree *  twicePi / triangleAmount)),
			y + (radius * sin(i_tree * twicePi / triangleAmount))
		);
	}
	glEnd();
	// Come Back real Position




	// Triangles-1
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.49, -0.38);
	glVertex2d(0.3, -0.42);
	glVertex2f(0.49, -0.43);
	glEnd();

	// Triangles-2
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.38);
	glVertex2d(0.65, -0.5);
	glVertex2f(0.5, -0.42);
	glEnd();

	// Triangles-3
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.5, -0.38);
	glVertex2d(0.55, -0.2);
	glVertex2f(0.52, -0.38);
	glEnd();

	glLoadIdentity();
	glPopMatrix();
	win += 0.1;
	glLoadIdentity();
	// End Windmill-2
	
	//-------------End Windmill-1 circle----------

	//================End Windmill====================

	// Road
	glBegin(GL_QUADS);
	glColor3ub(213, 214, 215);
	glVertex2f(-1, 0);
	glVertex2f(1, 0);
	glVertex2f(1, 0.3);
	glVertex2f(-1,0.3);
	glEnd();

	// Plain
	glBegin(GL_QUADS);
	glColor3ub(232, 236, 237);
	glVertex2f(-0.5, 0.2);
	glVertex2f(0.7, 0.5);
	glVertex2f(0.68, 0.8);
	glVertex2f(-0.52, 0.5);
	glEnd();

	// Triangles
	glBegin(GL_TRIANGLES);
	glColor3ub(232, 236, 237);
	glVertex2f(0.7, 0.5);
	glVertex2d(0.9, 0.58);
	glVertex2f(0.68, 0.7);
	glEnd();

	// start sun
	int i;

	 x = -0.8f;  y = 0.8f;  radius = .13f;
	 triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	 twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(246, 108, 141);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
	// End sun

	// All Code Render or Display
	glFlush();
}

void idielAir()
{
	glutPostRedisplay();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(520, 320);
	glutCreateWindow("Lab-3 Task 3 Airport View");
	//gluOrtho2D(-2, 2, -1, 1);
	glutDisplayFunc(AirportView);
	glutIdleFunc(idielAir);
	glutMainLoop();
	return 0;
}