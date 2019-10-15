#include "stdafx.h"
#include <GL/glut.h>
#include <cmath>

//const float DEG2RAD = 3.14159 / 180;

void AiubDBuilding(void)
{
	// Set Background Color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Display Clear
	glClear(GL_COLOR_BUFFER_BIT);

	//Road
	glBegin(GL_QUADS);
	glColor3ub(172, 177, 185);
	glVertex2f(-1, -0.9);
	glVertex2f(1, -0.9);
	glVertex2f(1, -0.6);
	glVertex2f(-1, -0.6);
	glEnd();

	//Floor
	glBegin(GL_QUADS);
	glColor3ub(231, 137, 137);
	glVertex2f(-1, -0.15);
	glVertex2f(1, -0.15);
	glVertex2f(0.9, -0.05);
	glVertex2f(-1, -0.05);
	glEnd();

	//I Card 1
	glBegin(GL_QUADS);
	glColor3ub(223, 217, 217);
	glVertex2f(-0.6, -0.05);
	glVertex2f(-0.55, -0.05);
	glVertex2f(-0.55, 0.1);
	glVertex2f(-0.6, 0.1);
	glEnd();

	//I Card 2
	glBegin(GL_QUADS);
	glColor3ub(223, 217, 217);
	glVertex2f(-0.5, -0.05);
	glVertex2f(-0.45, -0.05);
	glVertex2f(-0.45, 0.1);
	glVertex2f(-0.5, 0.1);
	glEnd();

	//I Card 3
	glBegin(GL_QUADS);
	glColor3ub(223, 217, 217);
	glVertex2f(-0.4, -0.05);
	glVertex2f(-0.35, -0.05);
	glVertex2f(-0.35, 0.1);
	glVertex2f(-0.4, 0.1);
	glEnd();

	//I Card 4
	glBegin(GL_QUADS);
	glColor3ub(223, 217, 217);
	glVertex2f(-0.3, -0.05);
	glVertex2f(-0.25, -0.05);
	glVertex2f(-0.25, 0.1);
	glVertex2f(-0.3, 0.1);
	glEnd();

	//I Card 5
	glBegin(GL_QUADS);
	glColor3ub(223, 217, 217);
	glVertex2f(-0.2, -0.05);
	glVertex2f(-0.15, -0.05);
	glVertex2f(-0.15, 0.1);
	glVertex2f(-0.2, 0.1);
	glEnd();

	//Gate 1
	glBegin(GL_QUADS);
	glColor3ub(222, 249, 238);
	glVertex2f(0.2, -0.05);
	glVertex2f(0.4, -0.05);
	glVertex2f(0.4, 0.3);
	glVertex2f(0.2, 0.3);
	glEnd();

	//Gate 2
	glBegin(GL_QUADS);
	glColor3ub(222, 249, 238);
	glVertex2f(0.6, -0.05);
	glVertex2f(0.8, -0.05);
	glVertex2f(0.8, 0.3);
	glVertex2f(0.6, 0.3);
	glEnd();

	//Middle Brim
	glBegin(GL_QUADS);
	glColor3ub(78, 101, 92);
	glVertex2f(-0.05, -0.05);
	glVertex2f(0.05, -0.05);
	glVertex2f(0.05, 0.6);
	glVertex2f(-0.05, 0.6);
	glEnd();

	//Start stairway 
	glBegin(GL_QUADS);
	glColor3ub(172, 177, 185);
	glVertex2f(-0.8, -0.5);
	glVertex2f(0.8, -0.5);
	glVertex2f(0.7, -0.15);
	glVertex2f(-0.7, -0.15);
	glEnd();

	//Line
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	//Down 1st
	glVertex2f(-0.78, -0.45);
	glVertex2f(0.78, -0.45);
	//Down 2nd
	glVertex2f(-0.76, -0.4);
	glVertex2f(0.76, -0.4);
	//Down 3rd
	glVertex2f(-0.75, -0.35);
	glVertex2f(0.75, -0.35);
	//Down 4th
	glVertex2f(-0.74, -0.3);
	glVertex2f(0.74, -0.3);
	//Down 5th
	glVertex2f(-0.725, -0.25);
	glVertex2f(0.725, -0.25);
	//Down 6th
	glVertex2f(-0.715, -0.2);
	glVertex2f(0.715, -0.2);
	//-------Handel Start--------
	glVertex2f(-0.7, -0.15);
	glVertex2f(-0.715, -0.05);

	glVertex2f(-0.8, -0.5);
	glVertex2f(-0.8, -0.4);

	glVertex2f(-0.8, -0.4);
	glVertex2f(-0.715, -0.05);
	//-------Handel End--------
	glEnd();

	// Right area-------------
	glBegin(GL_QUADS);
	glColor3ub(172, 177, 185);
	glVertex2f(0.8, -0.5);
	glVertex2f(1, -0.5);
	glVertex2f(1, -0.3);
	glVertex2f(0.9, -0.3);
	glEnd();


	//Right area Line
	glBegin(GL_LINES);
	glColor3f(255, 0, 0);

	glVertex2f(0.9, -0.3);
	glVertex2f(0.7, -0.15);

	glVertex2f(0.7, -0.15);
	glVertex2f(1, -0.15);

	//Left area Line
	glVertex2f(-0.7, -0.15);
	glVertex2f(-1, -0.15);
	glEnd();
	//End stairway 

	//Top Brim
	glBegin(GL_QUADS);
	glColor3ub(172, 177, 185);
	glVertex2f(-1, 0.4);
	glVertex2f(1, 0.4);
	glVertex2f(1, 0.6);
	glVertex2f(-1, 0.6);
	glEnd();

	//Left Wail
	/*glBegin(GL_QUADS);
	glColor3ub(172, 177, 185);
	glVertex2f(-1, -0.05);
	glVertex2f(-0.9, -0.05);
	glVertex2f(-0.9, 0.4);
	glVertex2f(-1, 0.4);
	glEnd();*/

	
	



	// All Code Render or Display
	glFlush();
}


/*int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lab-2 Task 2");
	glutDisplayFunc(AiubDBuilding);
	glutMainLoop();
	return 0;
}*/