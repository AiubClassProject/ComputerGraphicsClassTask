#include "stdafx.h"
//#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
#include <iostream>

# define PI  3.14159265358979323846
	GLfloat win = 0.0f;

	GLfloat XPosition1 = 0.2f;
	GLfloat YPosition1 = 0.9f;
	GLfloat XSpeed1 = 0.01f;               //0.06f;
	GLfloat YSpeed1 = 0.01f;               //0.05f;
										   //============

	GLfloat XPositionBird = -0.8f;
	GLfloat YPositionBird = 0.9f;
	GLfloat XSpeedBird = 0.06f;
	GLfloat YSpeedBird = 0.05f;

	void updateAutoFly(int value) {
		if (XPosition1 <-1.3)
		{
			XPosition1 = 0.2f;
			YPosition1 = 0.9f;
		}

		if (XPosition1<-0.3)
		{
			YPosition1 += YSpeed1;
		}

		XPosition1 -= XSpeed1;



		glutPostRedisplay();
		glutTimerFunc(100, updateAutoFly, 0);
	}


	void BirdFly(int value) {
		if (XPositionBird <1)
		{
			XPositionBird = -0.8f;
		}

		XPositionBird -= XSpeed1;

		glutPostRedisplay();
		glutTimerFunc(100, BirdFly, 0);
	}
	void updateLeft(int value) {
		if (XPosition1>-1.29)
		{
			XPosition1 -= XSpeed1;
		}
		glutPostRedisplay();
		glutTimerFunc(100, updateLeft, 0);
	}
	void updateRight(int value) {
		if (XPosition1<0.28)
		{
			XPosition1 += XSpeed1;
		}
		glutPostRedisplay();
		glutTimerFunc(100, updateRight, 0);
	}
	void updateUp(int value) {

		if (YPosition1<1.5)
		{
			YPosition1 += YSpeed1;
		}
		glutPostRedisplay();
		glutTimerFunc(100, updateUp, 0);
	}
	void updateDown(int value) {
		if (YPosition1>0.9)
		{
			YPosition1 -= YSpeed1;
		}

		glutPostRedisplay();
		glutTimerFunc(100, updateDown, 0);
	}


	void rain()
	{
		//Line
		glBegin(GL_LINES);
		glColor3f(255, 0, 0);

		glVertex2f(-0.2, -0.5);
		glVertex2f(-0.7, -0.5);

		glVertex2f(-0.2, -0.5);
		glVertex2f(-0.7, -0.1);

		glVertex2f(-0.2, -0.1);
		glVertex2f(-0.7, -0.1);
		glEnd();
	}
	void snow()
	{
		//Point
		glPointSize(1);
		glBegin(GL_POINT);
		glColor3f(255, 0, 0);
		glVertex2f(-0.2, -0.7);
		glEnd();
	}

	void AirportViewMorning(int value);

	void AirportViewNight(int value)
	{
		// Set Background Color
		glClearColor(0, 0, 0, 0.2);
		// Display Clear
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_LIGHTING);
		GLfloat global_ambient_night_ground[] = { 0, 0.9, 0, 0.1 };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_night_ground);

		// Green Ground
		glBegin(GL_QUADS);
		glColor3f(0.82, 0.89, 0.56);
		glVertex2f(-1, -1);
		glVertex2f(1, -1);
		glVertex2f(1, 0);
		glVertex2f(-1, 0);
		glEnd();
		glDisable(GL_LIGHTING);

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
		glEnable(GL_LIGHTING);
		GLfloat global_ambient_night_road[] = { 3, 3, 3,0.1 };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient_night_road);
		glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-1, 0);
		glVertex2f(1, 0);
		glVertex2f(1, 0.3);
		glVertex2f(-1, 0.3);
		glEnd();
		glDisable(GL_LIGHTING);

		/*// Plain
		glBegin(GL_QUADS);
		glColor3ub(232, 236, 237);
		glVertex2f(-0.5, 0.2);
		glVertex2f(0.7, 0.5);
		glVertex2f(0.68, 0.8);
		glVertex2f(-0.52, 0.5);
		glEnd();*/

		/*// Triangles
		glBegin(GL_TRIANGLES);
		glColor3ub(232, 236, 237);
		glVertex2f(0.7, 0.5);
		glVertex2d(0.9, 0.58);
		glVertex2f(0.68, 0.7);
		glEnd();*/

		// start sun
		int i;

		x = 0.8f;  y = 0.8f;  radius = .13f;
		triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
		twicePi = 2.0f * PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(255, 255, 255);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		// End sun

		//XPositionBird
		//===========Bird Start==============
		glTranslatef(XPositionBird, YPositionBird, 0);
		glBegin(GL_QUADS);
		glColor3ub(0, 0, 0);
		glVertex2f(-0.9f, 0.55f);
		glVertex2f(-0.8f, 0.6f);
		glVertex2f(-0.9f, 0.65f);
		glVertex2f(-1.0f, 0.6f);
		glEnd();

		x = -0.8f;  y = 0.6f;  radius = .02f;
		triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
		twicePi = 2.0f * PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0, 0, 0);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		glLoadIdentity();
		//===========Bird End==================



		//================Airplane Start =======================

		//GLfloat XPosition = 0.2f;
		//GLfloat YPosition = 0.9f;
		//glTranslatef(0.2f, 0.9f, 0);
		glTranslatef(XPosition1, YPosition1, 0);
		glBegin(GL_TRIANGLES);
		//front
		glColor3ub(255, 0, 0);
		glVertex2f(0.3f, -0.750f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.4f, -0.7f);
		glEnd();

		//body
		glBegin(GL_POLYGON);

		glColor3ub(255, 0, 0);
		glVertex2f(0.4f, -0.7f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.650f, -0.8f);
		glVertex2f(0.650f, -0.7f);

		glEnd();
		//back
		glBegin(GL_QUADS);

		glColor3ub(255, 0, 0);
		glVertex2f(0.650f, -0.7f);
		glVertex2f(0.650f, -0.8f);
		glVertex2f(0.7f, -0.8f);
		glVertex2f(0.7f, -0.620f);

		//wind
		glColor3ub(255, 0, 0);
		glVertex2f(0.550f, -0.610f);
		glVertex2f(0.450f, -0.7f);
		glVertex2f(0.520f, -0.7f);
		glVertex2f(0.6f, -0.630f);
		//window
		glColor3f(1, 1, 1);
		glVertex2f(0.450f, -0.730f);
		glVertex2f(0.450f, -0.760f);
		glVertex2f(0.5f, -0.760f);
		glVertex2f(0.5f, -0.730f);
		//window
		glColor3f(1, 1, 1);
		glVertex2f(0.550f, -0.730f);
		glVertex2f(0.550f, -0.760f);
		glVertex2f(0.6f, -0.760f);
		glVertex2f(0.6f, -0.730f);
		glEnd();

		//wheel

		//circle for wheel 1st

		//glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
		//glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
		glColor3ub(255, 0, 0);

		GLfloat xNewAir = 0.450f; GLfloat yNewAir = -0.820f; GLfloat radiusNewAir = .03f;
		int iNewAir;
		int lineAmount = 100; //# of triangles used to draw circle

							  //GLfloat radius = 0.8f; //radius
		GLfloat twicePiiNewAir = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (iNewAir = 0; iNewAir <= lineAmount; iNewAir++) {
			glVertex2f(
				xNewAir + (radiusNewAir * cos(iNewAir *  twicePiiNewAir / lineAmount)),
				yNewAir + (radiusNewAir* sin(iNewAir * twicePiiNewAir / lineAmount))
			);
		}
		glEnd();


		//2nd circle

		GLfloat x2 = 0.570f; GLfloat y2 = -0.820f; GLfloat radius2 = .01f;
		int j;
		int lineAmount2 = 100; //# of triangles used to draw circle

							   //GLfloat radius = 0.8f; //radius
		GLfloat twicePi2 = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (j = 0; j <= lineAmount2; j++) {
			glVertex2f(
				x2 + (radiusNewAir * cos(j *  twicePi2 / lineAmount2)),
				y2 + (radiusNewAir* sin(j * twicePi2 / lineAmount2))
			);
		}
		glEnd();


		//3rd

		GLfloat x3 = 0.63f; GLfloat y3 = -0.820f; GLfloat radius3 = .01f;
		int k;
		int lineAmount3 = 100; //# of triangles used to draw circle

							   //GLfloat radius = 0.8f; //radius
		GLfloat twicePi3 = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (k = 0; k <= lineAmount3; k++) {
			glVertex2f(
				x3 + (radiusNewAir * cos(k *  twicePi3 / lineAmount3)),
				y3 + (radiusNewAir* sin(k * twicePi3 / lineAmount3))
			);
		}
		glEnd();
		glLoadIdentity();

		//==================Airplane End===========================

		//Start Rain
		//Line
		glBegin(GL_LINES);
		glColor3f(255, 255, 255);
		// X
		glVertex2f(-0.9, 0.9);
		glVertex2f(-0.85, 0.85);

		glVertex2f(-0.8, 0.9);
		glVertex2f(-0.75, 0.85);

		glVertex2f(-0.7, 0.9);
		glVertex2f(-0.65, 0.85);

		glVertex2f(-0.6, 0.9);
		glVertex2f(-0.55, 0.85);

		glVertex2f(-0.5, 0.9);
		glVertex2f(-0.45, 0.85);

		glVertex2f(-0.4, 0.9);
		glVertex2f(-0.35, 0.85);

		glVertex2f(-0.3, 0.9);
		glVertex2f(-0.25, 0.85);

		glVertex2f(-0.2, 0.9);
		glVertex2f(-0.15, 0.85);

		glVertex2f(-0.1, 0.9);
		glVertex2f(-0.05, 0.85);

		glVertex2f(0.1, 0.9);
		glVertex2f(0.15, 0.85);
		glEnd();



		// All Code Render or Display
		glFlush();

		glutTimerFunc(200, AirportViewNight, 0);
	}
    //end Night View


	void AirportViewDay(int value)
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
		glVertex2f(-1, 0.3);
		glEnd();

		/*// Plain
		glBegin(GL_QUADS);
		glColor3ub(232, 236, 237);
		glVertex2f(-0.5, 0.2);
		glVertex2f(0.7, 0.5);
		glVertex2f(0.68, 0.8);
		glVertex2f(-0.52, 0.5);
		glEnd();*/

		/*// Triangles
		glBegin(GL_TRIANGLES);
		glColor3ub(232, 236, 237);
		glVertex2f(0.7, 0.5);
		glVertex2d(0.9, 0.58);
		glVertex2f(0.68, 0.7);
		glEnd();*/

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

		//XPositionBird
		//===========Bird Start==============
		glTranslatef(XPositionBird, YPositionBird, 0);
		glBegin(GL_QUADS);
		glColor3ub(0, 0, 0);
		glVertex2f(-0.9f, 0.55f);
		glVertex2f(-0.8f, 0.6f);
		glVertex2f(-0.9f, 0.65f);
		glVertex2f(-1.0f, 0.6f);
		glEnd();

		x = -0.8f;  y = 0.6f;  radius = .02f;
		triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
		twicePi = 2.0f * PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0, 0, 0);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		glLoadIdentity();
		//===========Bird End==================



		//================Airplane Start =======================

		//GLfloat XPosition = 0.2f;
		//GLfloat YPosition = 0.9f;
		//glTranslatef(0.2f, 0.9f, 0);
		glTranslatef(XPosition1, YPosition1, 0);
		glBegin(GL_TRIANGLES);
		//front
		glColor3ub(255, 0, 0);
		glVertex2f(0.3f, -0.750f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.4f, -0.7f);
		glEnd();

		//body
		glBegin(GL_POLYGON);

		glColor3ub(255, 0, 0);
		glVertex2f(0.4f, -0.7f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.650f, -0.8f);
		glVertex2f(0.650f, -0.7f);

		glEnd();
		//back
		glBegin(GL_QUADS);

		glColor3ub(255, 0, 0);
		glVertex2f(0.650f, -0.7f);
		glVertex2f(0.650f, -0.8f);
		glVertex2f(0.7f, -0.8f);
		glVertex2f(0.7f, -0.620f);

		//wind
		glColor3ub(255, 0, 0);
		glVertex2f(0.550f, -0.610f);
		glVertex2f(0.450f, -0.7f);
		glVertex2f(0.520f, -0.7f);
		glVertex2f(0.6f, -0.630f);
		//window
		glColor3ub(0, 0, 0);
		glVertex2f(0.450f, -0.730f);
		glVertex2f(0.450f, -0.760f);
		glVertex2f(0.5f, -0.760f);
		glVertex2f(0.5f, -0.730f);
		//window
		glColor3ub(0, 0, 0);
		glVertex2f(0.550f, -0.730f);
		glVertex2f(0.550f, -0.760f);
		glVertex2f(0.6f, -0.760f);
		glVertex2f(0.6f, -0.730f);
		glEnd();

		//wheel

		//circle for wheel 1st

		//glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
		//glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
		glColor3ub(255, 0, 0);

		GLfloat xNewAir = 0.450f; GLfloat yNewAir = -0.820f; GLfloat radiusNewAir = .03f;
		int iNewAir;
		int lineAmount = 100; //# of triangles used to draw circle

							  //GLfloat radius = 0.8f; //radius
		GLfloat twicePiiNewAir = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (iNewAir = 0; iNewAir <= lineAmount; iNewAir++) {
			glVertex2f(
				xNewAir + (radiusNewAir * cos(iNewAir *  twicePiiNewAir / lineAmount)),
				yNewAir + (radiusNewAir* sin(iNewAir * twicePiiNewAir / lineAmount))
			);
		}
		glEnd();


		//2nd circle

		GLfloat x2 = 0.570f; GLfloat y2 = -0.820f; GLfloat radius2 = .01f;
		int j;
		int lineAmount2 = 100; //# of triangles used to draw circle

							   //GLfloat radius = 0.8f; //radius
		GLfloat twicePi2 = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (j = 0; j <= lineAmount2; j++) {
			glVertex2f(
				x2 + (radiusNewAir * cos(j *  twicePi2 / lineAmount2)),
				y2 + (radiusNewAir* sin(j * twicePi2 / lineAmount2))
			);
		}
		glEnd();


		//3rd

		GLfloat x3 = 0.63f; GLfloat y3 = -0.820f; GLfloat radius3 = .01f;
		int k;
		int lineAmount3 = 100; //# of triangles used to draw circle

							   //GLfloat radius = 0.8f; //radius
		GLfloat twicePi3 = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (k = 0; k <= lineAmount3; k++) {
			glVertex2f(
				x3 + (radiusNewAir * cos(k *  twicePi3 / lineAmount3)),
				y3 + (radiusNewAir* sin(k * twicePi3 / lineAmount3))
			);
		}
		glEnd();
		glLoadIdentity();

		//==================Airplane End===========================



		// All Code Render or Display
		glFlush();
		glutTimerFunc(0, AirportViewDay, 0);
	}

	void AirportViewMorning(int value)
	{
		// Set Background Color
		glClearColor(102, 0, 102, 0.2);
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
		glVertex2f(-1, 0.3);
		glEnd();

		/*// Plain
		glBegin(GL_QUADS);
		glColor3ub(232, 236, 237);
		glVertex2f(-0.5, 0.2);
		glVertex2f(0.7, 0.5);
		glVertex2f(0.68, 0.8);
		glVertex2f(-0.52, 0.5);
		glEnd();*/

		/*// Triangles
		glBegin(GL_TRIANGLES);
		glColor3ub(232, 236, 237);
		glVertex2f(0.7, 0.5);
		glVertex2d(0.9, 0.58);
		glVertex2f(0.68, 0.7);
		glEnd();*/

		// start sun
		int i;

		x = -0.8f;  y = 0.8f;  radius = .13f;
		triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
		twicePi = 2.0f * PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(250, 0, 0);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		// End sun

		//XPositionBird
		//===========Bird Start==============
		glTranslatef(XPositionBird, YPositionBird, 0);
		glBegin(GL_QUADS);
		glColor3ub(0, 0, 0);
		glVertex2f(-0.9f, 0.55f);
		glVertex2f(-0.8f, 0.6f);
		glVertex2f(-0.9f, 0.65f);
		glVertex2f(-1.0f, 0.6f);
		glEnd();

		x = -0.8f;  y = 0.6f;  radius = .02f;
		triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
		twicePi = 2.0f * PI;

		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0, 0, 0);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		glLoadIdentity();
		//===========Bird End==================



		//================Airplane Start =======================

		//GLfloat XPosition = 0.2f;
		//GLfloat YPosition = 0.9f;
		//glTranslatef(0.2f, 0.9f, 0);
		glTranslatef(XPosition1, YPosition1, 0);
		glBegin(GL_TRIANGLES);
		//front
		glColor3ub(255, 0, 0);
		glVertex2f(0.3f, -0.750f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.4f, -0.7f);
		glEnd();

		//body
		glBegin(GL_POLYGON);

		glColor3ub(255, 0, 0);
		glVertex2f(0.4f, -0.7f);
		glVertex2f(0.4f, -0.8f);
		glVertex2f(0.650f, -0.8f);
		glVertex2f(0.650f, -0.7f);

		glEnd();
		//back
		glBegin(GL_QUADS);

		glColor3ub(255, 0, 0);
		glVertex2f(0.650f, -0.7f);
		glVertex2f(0.650f, -0.8f);
		glVertex2f(0.7f, -0.8f);
		glVertex2f(0.7f, -0.620f);

		//wind
		glColor3ub(255, 0, 0);
		glVertex2f(0.550f, -0.610f);
		glVertex2f(0.450f, -0.7f);
		glVertex2f(0.520f, -0.7f);
		glVertex2f(0.6f, -0.630f);
		//window
		glColor3ub(0, 0, 0);
		glVertex2f(0.450f, -0.730f);
		glVertex2f(0.450f, -0.760f);
		glVertex2f(0.5f, -0.760f);
		glVertex2f(0.5f, -0.730f);
		//window
		glColor3ub(0, 0, 0);
		glVertex2f(0.550f, -0.730f);
		glVertex2f(0.550f, -0.760f);
		glVertex2f(0.6f, -0.760f);
		glVertex2f(0.6f, -0.730f);
		glEnd();

		//wheel

		//circle for wheel 1st

		//glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
		//glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
		glColor3ub(255, 0, 0);

		GLfloat xNewAir = 0.450f; GLfloat yNewAir = -0.820f; GLfloat radiusNewAir = .03f;
		int iNewAir;
		int lineAmount = 100; //# of triangles used to draw circle

							  //GLfloat radius = 0.8f; //radius
		GLfloat twicePiiNewAir = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (iNewAir = 0; iNewAir <= lineAmount; iNewAir++) {
			glVertex2f(
				xNewAir + (radiusNewAir * cos(iNewAir *  twicePiiNewAir / lineAmount)),
				yNewAir + (radiusNewAir* sin(iNewAir * twicePiiNewAir / lineAmount))
			);
		}
		glEnd();


		//2nd circle

		GLfloat x2 = 0.570f; GLfloat y2 = -0.820f; GLfloat radius2 = .01f;
		int j;
		int lineAmount2 = 100; //# of triangles used to draw circle

							   //GLfloat radius = 0.8f; //radius
		GLfloat twicePi2 = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (j = 0; j <= lineAmount2; j++) {
			glVertex2f(
				x2 + (radiusNewAir * cos(j *  twicePi2 / lineAmount2)),
				y2 + (radiusNewAir* sin(j * twicePi2 / lineAmount2))
			);
		}
		glEnd();


		//3rd

		GLfloat x3 = 0.63f; GLfloat y3 = -0.820f; GLfloat radius3 = .01f;
		int k;
		int lineAmount3 = 100; //# of triangles used to draw circle

							   //GLfloat radius = 0.8f; //radius
		GLfloat twicePi3 = 2.0f * PI;

		glBegin(GL_LINE_LOOP);
		for (k = 0; k <= lineAmount3; k++) {
			glVertex2f(
				x3 + (radiusNewAir * cos(k *  twicePi3 / lineAmount3)),
				y3 + (radiusNewAir* sin(k * twicePi3 / lineAmount3))
			);
		}
		glEnd();
		glLoadIdentity();

		//==================Airplane End===========================



		// All Code Render or Display
		glFlush();
		glutTimerFunc(0, AirportViewMorning, 0);
	}





	void handleMouse(int button, int state, int x, int y)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			XSpeed1 += 0.01f;
		}
		if (button == GLUT_RIGHT_BUTTON)
		{
			XSpeed1 -= 0.01f;
		}
		glutPostRedisplay();
	}

	void handleKeypress(unsigned char key, int x, int y)
	{
		switch (key)
		{
		case 'a':
			XSpeed1 = 0.01f;
			YSpeed1 = 0.01f;
			glutTimerFunc(100, updateAutoFly, 0);
			break;
		case 's':
			XSpeed1 = 0.0f;
			YSpeed1 = 0.0f;
			break;
		case'm':
			glutTimerFunc(100, AirportViewMorning, 0);
			break;

		case'd':
			glutTimerFunc(100, AirportViewDay, 0);
			break;
		case'n':
			glutTimerFunc(100, AirportViewNight, 0);
			break;
		}
		glutPostRedisplay();
	}



	void idielAir()
	{
		glutPostRedisplay();
	}


	void SpecialInputForAirportView(int key, int x, int y)
	{
		switch (key)
		{
		case GLUT_KEY_UP:
			glutTimerFunc(100, updateUp, 0);
			break;
		case GLUT_KEY_DOWN:
			glutTimerFunc(100, updateDown, 0);
			break;
		case GLUT_KEY_LEFT:
			glutTimerFunc(100, updateLeft, 0);
			break;
		case GLUT_KEY_RIGHT:
			glutTimerFunc(100, updateRight, 0);
			break;
		}
		glutPostRedisplay();
	}

	/*
	int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitWindowSize(520, 320);
		glutCreateWindow("Lab-3 Task 3 Airport View");
		//gluOrtho2D(-2, 2, -1, 1);

		//glutDisplayFunc(AirportView);
		//glutDisplayFunc(AirportViewNight);
		
		//glutTimerFunc(100, updateAutoFly, 0);

		glutIdleFunc(idielAir);
		glutSpecialFunc(SpecialInputForAirportView);

		//Press Other Key
		glutKeyboardFunc(handleKeypress);
		//Press Mouse Button
		glutMouseFunc(handleMouse);
		glutMainLoop();
		return 0;
	}
	*/


