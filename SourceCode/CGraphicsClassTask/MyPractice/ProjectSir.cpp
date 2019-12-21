
/*
-------------------------------------------------
|Designed as Class-Assignment by				|
-------------------------------------------------
-------------------------------------------------
|Shovra	Das										|
|Student										|
|American International University-Bangladesh	|
-------------------------------------------------

-------------------------------------------------
|Keboard Shortcuts								|
-------------------------------------------------
-------------------------------------------------
|x -rotate w.r.t to x axis						|
|y -rotate w.r.t to y axis						|
|z -rotate w.r.t to z axis						|
|a -rotate w.r.t to all axis					|
|i -zoom in										|
|o -zoom out									|
|r -rotate										|
|R -rotate reverse								|
|f -front view									|
|s -set to initial								|
|g -go for desired scene						|
|v -translate +ve y axis						|
|V -translate -ve y axis						|
-------------------------------------------------
*/
#include "stdafx.h"
//#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>

static GLfloat spin = 45.0;
static GLfloat spin_speed = 0.2;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -850.0;



void init()
{
	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_FLAT);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing


}

///------- custom functions starts -------

void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}

void set()
{
	spin = 45.0;
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = -850.0;

}

void go()
{
	spin = 40.0;
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = 0.0;
	translate_z = -645.0;
}

///------- custom functions ends   -------

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 10.0f, 10000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(translate_x, translate_y, translate_z);
	glRotatef(spin, spin_x, spin_y, spin_z);

	///------- custom code starts -------

	///////////// roof starts /////////////
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
	//back plane
	glVertex3f(-440, 80, -430);
	glVertex3f(440, 80, -430);
	glVertex3f(440, 90, -430);
	glVertex3f(-440, 90, -430);
	//front plane
	glVertex3f(-440, 80, 450);
	glVertex3f(440, 80, 450);
	glVertex3f(440, 90, 450);
	glVertex3f(-440, 90, 450);
	//right plane
	glVertex3f(-440, 80, -430);
	glVertex3f(-440, 90, -430);
	glVertex3f(-440, 90, 450);
	glVertex3f(-440, 80, 450);
	//left plane
	glVertex3f(440, 80, -430);
	glVertex3f(440, 90, -430);
	glVertex3f(440, 90, 450);
	glVertex3f(440, 80, 450);
	//bottom plane
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-440, 80, -430);
	glVertex3f(440, 80, -430);
	glVertex3f(440, 80, 450);
	glVertex3f(-440, 80, 450);
	//top plane
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-440, 90, -430);
	glVertex3f(440, 90, -430);
	glVertex3f(440, 90, 450);
	glVertex3f(-440, 90, 450);
	glEnd();
	///////////// roof ends /////////////

	///////////// floor starts /////////////
	glBegin(GL_QUADS);
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-430, -75, -430);
	glVertex3f(430, -75, -430);
	glVertex3f(430, -90, -430);
	glVertex3f(-430, -90, -430);
	//front plane
	glVertex3f(-430, -75, 430);
	glVertex3f(430, -75, 430);
	glVertex3f(430, -90, 430);
	glVertex3f(-430, -90, 430);
	//right plane
	glVertex3f(-430, -75, -430);
	glVertex3f(-430, -90, -430);
	glVertex3f(-430, -90, 430);
	glVertex3f(-430, -75, 430);
	//left plane
	glVertex3f(430, -75, -430);
	glVertex3f(430, -90, -430);
	glVertex3f(430, -90, 430);
	glVertex3f(430, -75, 430);
	//top plane
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-430, -75, -430);
	glVertex3f(430, -75, -430);
	glVertex3f(430, -75, 430);
	glVertex3f(-430, -75, 430);
	//bottom plane
	glVertex3f(-430, -90, -430);
	glVertex3f(430, -90, -430);
	glVertex3f(430, -90, 430);
	glVertex3f(-430, -90, 430);
	glEnd();
	///////////// floor ends /////////////



	///////////// wall starts /////////////
	glBegin(GL_QUADS);

	//---- back wall back ----
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-420, 80, -420);
	glVertex3f(420, 80, -420);
	glVertex3f(420, -75, -420);
	glVertex3f(-420, -75, -420);
	//------------------------

	//---- left wall back ----
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-420, 80, -420);
	glVertex3f(-420, -75, -420);
	glVertex3f(-420, -75, 420);
	glVertex3f(-420, 80, 420);
	//------------------------

	//---- right wall back ----
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(420, 80, -420);
	glVertex3f(420, -75, -420);
	glVertex3f(420, -75, 420);
	glVertex3f(420, 80, 420);
	//------------------------

	//----- large wall-i --------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-270, 75, -410);
	glVertex3f(-270, -75, -410);
	glVertex3f(-420, -75, -410);
	//front plane
	glVertex3f(-420, 75, -420);
	glVertex3f(-270, 75, -420);
	glVertex3f(-270, -75, -420);
	glVertex3f(-420, -75, -420);
	//right plane
	glVertex3f(-270, 75, -410);
	glVertex3f(-270, -75, -410);
	glVertex3f(-270, -75, -420);
	glVertex3f(-270, 75, -420);
	//left plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, -75, -410);
	glVertex3f(-420, -75, -420);
	glVertex3f(-420, 75, -420);
	//top plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-270, 75, -410);
	glVertex3f(-270, 75, -420);
	glVertex3f(-420, 75, -420);
	//bottom plane
	glVertex3f(-420, -75, -410);
	glVertex3f(-270, -75, -410);
	glVertex3f(-270, -75, -420);
	glVertex3f(-420, -75, -420);
	//-----------------------------

	//------- separator-i --------
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-265, 65, -415);
	glVertex3f(-250, 65, -415);
	glVertex3f(-250, -65, -415);
	glVertex3f(-265, -65, -415);
	//--------------------------

	//------ small wall-i -------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(-245, 75, -410);
	glVertex3f(-215, 75, -410);
	glVertex3f(-215, -75, -410);
	glVertex3f(-245, -75, -410);
	//front plane
	glVertex3f(-245, 75, -420);
	glVertex3f(-215, 75, -420);
	glVertex3f(-215, -75, -420);
	glVertex3f(-245, -75, -420);
	//right plane
	glVertex3f(-215, 75, -410);
	glVertex3f(-215, -75, -410);
	glVertex3f(-215, -75, -420);
	glVertex3f(-215, 75, -420);
	//left plane
	glVertex3f(-245, 75, -410);
	glVertex3f(-245, -75, -410);
	glVertex3f(-245, -75, -420);
	glVertex3f(-245, 75, -420);
	//top plane
	glVertex3f(-245, 75, -410);
	glVertex3f(-215, 75, -410);
	glVertex3f(-215, 75, -420);
	glVertex3f(-245, 75, -420);
	//bottom plane
	glVertex3f(-245, -75, -410);
	glVertex3f(-215, -75, -410);
	glVertex3f(-215, -75, -420);
	glVertex3f(-245, -75, -420);
	//-----------------------------

	//------- separator-ii --------
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-210, 65, -415);
	glVertex3f(-195, 65, -415);
	glVertex3f(-195, -65, -415);
	glVertex3f(-210, -65, -415);
	//--------------------------

	//------ large wall-ii -------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(-190, 75, -410);
	glVertex3f(-40, 75, -410);
	glVertex3f(-40, -75, -410);
	glVertex3f(-190, -75, -410);
	//front plane
	glVertex3f(-190, 75, -420);
	glVertex3f(-40, 75, -420);
	glVertex3f(-40, -75, -420);
	glVertex3f(-190, -75, -420);
	//right plane
	glVertex3f(-40, 75, -410);
	glVertex3f(-40, -75, -410);
	glVertex3f(-40, -75, -420);
	glVertex3f(-40, 75, -420);
	//left plane
	glVertex3f(-190, 75, -410);
	glVertex3f(-190, -75, -410);
	glVertex3f(-190, -75, -420);
	glVertex3f(-190, 75, -420);
	//top plane
	glVertex3f(-190, 75, -410);
	glVertex3f(-40, 75, -410);
	glVertex3f(-40, 75, -420);
	glVertex3f(-190, 75, -420);
	//bottom plane
	glVertex3f(-190, -75, -410);
	glVertex3f(-40, -75, -410);
	glVertex3f(-40, -75, -420);
	glVertex3f(-190, -75, -420);
	//-----------------------------

	//------- separator-iii --------
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-35, 65, -415);
	glVertex3f(-20, 65, -415);
	glVertex3f(-20, -65, -415);
	glVertex3f(-35, -65, -415);
	//--------------------------

	//------ small wall-ii -------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(-15, 75, -410);
	glVertex3f(15, 75, -410);
	glVertex3f(15, -75, -410);
	glVertex3f(-15, -75, -410);
	//front plane
	glVertex3f(-15, 75, -420);
	glVertex3f(15, 75, -420);
	glVertex3f(15, -75, -420);
	glVertex3f(-15, -75, -420);
	//right plane
	glVertex3f(15, 75, -410);
	glVertex3f(15, -75, -410);
	glVertex3f(15, -75, -420);
	glVertex3f(15, 75, -420);
	//left plane
	glVertex3f(-15, 75, -410);
	glVertex3f(-15, -75, -410);
	glVertex3f(-15, -75, -420);
	glVertex3f(-15, 75, -420);
	//top plane
	glVertex3f(-15, 75, -410);
	glVertex3f(15, 75, -410);
	glVertex3f(15, 75, -420);
	glVertex3f(-15, 75, -420);
	//bottom plane
	glVertex3f(-15, -75, -410);
	glVertex3f(15, -75, -410);
	glVertex3f(15, -75, -420);
	glVertex3f(-15, -75, -420);
	//-----------------------------

	//----- large wall-iii --------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(-5, 75, -410);
	glVertex3f(5, 75, -410);
	glVertex3f(5, -75, -410);
	glVertex3f(-5, -75, -410);
	//front plane
	glVertex3f(-5, 75, -105);
	glVertex3f(5, 75, -105);
	glVertex3f(5, -75, -105);
	glVertex3f(-5, -75, -105);
	//right plane
	glVertex3f(5, 75, -410);
	glVertex3f(5, -75, -410);
	glVertex3f(5, -75, -105);
	glVertex3f(5, 75, -105);
	//left plane
	glVertex3f(-5, 75, -410);
	glVertex3f(-5, -75, -410);
	glVertex3f(-5, -75, -105);
	glVertex3f(-5, 75, -105);
	//top plane
	glVertex3f(-5, 75, -410);
	glVertex3f(5, 75, -410);
	glVertex3f(5, 75, -105);
	glVertex3f(-5, 75, -105);
	//bottom plane
	glVertex3f(-5, -75, -410);
	glVertex3f(5, -75, -410);
	glVertex3f(5, -75, -105);
	glVertex3f(-5, -75, -105);
	//-----------------------------

	//------- separator-iv --------
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20, 65, -415);
	glVertex3f(35, 65, -415);
	glVertex3f(35, -65, -415);
	glVertex3f(20, -65, -415);
	//--------------------------

	//------ large wall-iv -------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(190, 75, -410);
	glVertex3f(40, 75, -410);
	glVertex3f(40, -75, -410);
	glVertex3f(190, -75, -410);
	//front plane
	glVertex3f(190, 75, -420);
	glVertex3f(40, 75, -420);
	glVertex3f(40, -75, -420);
	glVertex3f(190, -75, -420);
	//right plane
	glVertex3f(40, 75, -410);
	glVertex3f(40, -75, -410);
	glVertex3f(40, -75, -420);
	glVertex3f(40, 75, -420);
	//left plane
	glVertex3f(190, 75, -410);
	glVertex3f(190, -75, -410);
	glVertex3f(190, -75, -420);
	glVertex3f(190, 75, -420);
	//top plane
	glVertex3f(190, 75, -410);
	glVertex3f(40, 75, -410);
	glVertex3f(40, 75, -420);
	glVertex3f(190, 75, -420);
	//bottom plane
	glVertex3f(190, -75, -410);
	glVertex3f(40, -75, -410);
	glVertex3f(40, -75, -420);
	glVertex3f(190, -75, -420);
	//-----------------------------

	//------- separator-v --------
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(210, 65, -415);
	glVertex3f(195, 65, -415);
	glVertex3f(195, -65, -415);
	glVertex3f(210, -65, -415);
	//--------------------------

	//------ small wall-iii -------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(245, 75, -410);
	glVertex3f(215, 75, -410);
	glVertex3f(215, -75, -410);
	glVertex3f(245, -75, -410);
	//front plane
	glVertex3f(245, 75, -420);
	glVertex3f(215, 75, -420);
	glVertex3f(215, -75, -420);
	glVertex3f(245, -75, -420);
	//right plane
	glVertex3f(215, 75, -410);
	glVertex3f(215, -75, -410);
	glVertex3f(215, -75, -420);
	glVertex3f(215, 75, -420);
	//left plane
	glVertex3f(245, 75, -410);
	glVertex3f(245, -75, -410);
	glVertex3f(245, -75, -420);
	glVertex3f(245, 75, -420);
	//top plane
	glVertex3f(245, 75, -410);
	glVertex3f(215, 75, -410);
	glVertex3f(215, 75, -420);
	glVertex3f(245, 75, -420);
	//bottom plane
	glVertex3f(245, -75, -410);
	glVertex3f(215, -75, -410);
	glVertex3f(215, -75, -420);
	glVertex3f(245, -75, -420);
	//---------------------------

	//------- separator-vi --------
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(265, 65, -415);
	glVertex3f(250, 65, -415);
	glVertex3f(250, -65, -415);
	glVertex3f(265, -65, -415);
	//--------------------------

	//----- large wall-iv --------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(420, 75, -410);
	glVertex3f(270, 75, -410);
	glVertex3f(270, -75, -410);
	glVertex3f(420, -75, -410);
	//front plane
	glVertex3f(420, 75, -420);
	glVertex3f(270, 75, -420);
	glVertex3f(270, -75, -420);
	glVertex3f(420, -75, -420);
	//right plane
	glVertex3f(270, 75, -410);
	glVertex3f(270, -75, -410);
	glVertex3f(270, -75, -420);
	glVertex3f(270, 75, -420);
	//left plane
	glVertex3f(420, 75, -410);
	glVertex3f(420, -75, -410);
	glVertex3f(420, -75, -420);
	glVertex3f(420, 75, -420);
	//top plane
	glVertex3f(420, 75, -410);
	glVertex3f(270, 75, -410);
	glVertex3f(270, 75, -420);
	glVertex3f(420, 75, -420);
	//bottom plane
	glVertex3f(420, -75, -410);
	glVertex3f(270, -75, -410);
	glVertex3f(270, -75, -420);
	glVertex3f(420, -75, -420);
	//-----------------------------

	//----- left wall --------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(-410, 75, -410);
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, -75, -410);
	glVertex3f(-410, -75, -410);
	//front plane
	glVertex3f(-410, 75, 420);
	glVertex3f(-420, 75, 420);
	glVertex3f(-420, -75, 420);
	glVertex3f(-410, -75, 420);
	//right plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, -75, -410);
	glVertex3f(-420, -75, 420);
	glVertex3f(-420, 75, 420);
	//left plane
	glVertex3f(-410, 75, -410);
	glVertex3f(-410, -75, -410);
	glVertex3f(-410, -75, 420);
	glVertex3f(-410, 75, 420);
	//top plane
	glVertex3f(-410, 75, -410);
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, 75, 420);
	glVertex3f(-410, 75, 420);
	//bottom plane
	glVertex3f(-410, -75, -410);
	glVertex3f(-420, -75, -410);
	glVertex3f(-420, -75, 420);
	glVertex3f(-410, -75, 420);
	//-----------------------------

	//----- right wall --------
	glColor3f(0.8, 0.8, 0.8);
	//back plane
	glVertex3f(410, 75, -410);
	glVertex3f(420, 75, -410);
	glVertex3f(420, -75, -410);
	glVertex3f(410, -75, -410);
	//front plane
	glVertex3f(410, 75, 420);
	glVertex3f(420, 75, 420);
	glVertex3f(420, -75, 420);
	glVertex3f(410, -75, 420);
	//right plane
	glVertex3f(420, 75, -410);
	glVertex3f(420, -75, -410);
	glVertex3f(420, -75, 420);
	glVertex3f(420, 75, 420);
	//left plane
	glVertex3f(410, 75, -410);
	glVertex3f(410, -75, -410);
	glVertex3f(410, -75, 420);
	glVertex3f(410, 75, 420);
	//top plane
	glVertex3f(410, 75, -410);
	glVertex3f(420, 75, -410);
	glVertex3f(420, 75, 420);
	glVertex3f(410, 75, 420);
	//bottom plane
	glVertex3f(410, -75, -410);
	glVertex3f(420, -75, -410);
	glVertex3f(420, -75, 420);
	glVertex3f(410, -75, 420);
	//-----------------------------

	glEnd();
	///////////// wall ends /////////////

	///////////// poll starts /////////////

	glBegin(GL_QUADS);

	//---- top poll_x-back -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(-420, 75, -410);
	glVertex3f(420, 75, -410);
	glVertex3f(420, 80, -410);
	glVertex3f(-420, 80, -410);
	//front plane
	glVertex3f(-420, 75, -420);
	glVertex3f(420, 75, -420);
	glVertex3f(420, 80, -420);
	glVertex3f(-420, 80, -420);
	//right plane
	glVertex3f(420, 75, -410);
	glVertex3f(420, 80, -410);
	glVertex3f(420, 80, -420);
	glVertex3f(420, 75, -420);
	//left plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, 80, -410);
	glVertex3f(-420, 80, -420);
	glVertex3f(-420, 75, -420);
	//top plane
	glVertex3f(-420, 80, -410);
	glVertex3f(420, 80, -410);
	glVertex3f(420, 80, -420);
	glVertex3f(-420, 80, -420);
	//bottom plane
	glVertex3f(-420, 75, -410);
	glVertex3f(420, 75, -410);
	glVertex3f(420, 75, -420);
	glVertex3f(-420, 75, -420);
	///----------------------------

	//---- top poll_x-front -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(-420, 75, 410);
	glVertex3f(420, 75, 410);
	glVertex3f(420, 80, 410);
	glVertex3f(-420, 80, 410);
	//front plane
	glVertex3f(-420, 75, 420);
	glVertex3f(420, 75, 420);
	glVertex3f(420, 80, 420);
	glVertex3f(-420, 80, 420);
	//right plane
	glVertex3f(420, 75, 410);
	glVertex3f(420, 80, 410);
	glVertex3f(420, 80, 420);
	glVertex3f(420, 75, 420);
	//left plane
	glVertex3f(-420, 75, 410);
	glVertex3f(-420, 80, 410);
	glVertex3f(-420, 80, 420);
	glVertex3f(-420, 75, 420);
	//top plane
	glVertex3f(-420, 80, 410);
	glVertex3f(420, 80, 410);
	glVertex3f(420, 80, 420);
	glVertex3f(-420, 80, 420);
	//bottom plane
	glVertex3f(-420, 75, 410);
	glVertex3f(420, 75, 410);
	glVertex3f(420, 75, 420);
	glVertex3f(-420, 75, 420);
	///----------------------------

	//---- top poll_z-left -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-410, 75, -410);
	glVertex3f(-410, 80, -410);
	glVertex3f(-420, 80, -410);
	//front plane
	glVertex3f(-420, 75, 410);
	glVertex3f(-410, 75, 410);
	glVertex3f(-410, 80, 410);
	glVertex3f(-420, 80, 410);
	//right plane
	glVertex3f(-410, 75, -410);
	glVertex3f(-410, 80, -410);
	glVertex3f(-410, 80, 410);
	glVertex3f(-410, 75, 410);
	//left plane
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, 80, -410);
	glVertex3f(-420, 80, 410);
	glVertex3f(-420, 75, 410);
	//top plane
	glVertex3f(-420, 80, -410);
	glVertex3f(-410, 80, -410);
	glVertex3f(-410, 80, 410);
	glVertex3f(-420, 80, 410);
	//bottom plane
	glVertex3f(-410, 75, -410);
	glVertex3f(-420, 75, -410);
	glVertex3f(-420, 75, 410);
	glVertex3f(-410, 75, 410);
	///----------------------------

	//---- top poll_z-right -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(420, 75, -410);
	glVertex3f(410, 75, -410);
	glVertex3f(410, 80, -410);
	glVertex3f(420, 80, -410);
	//front plane
	glVertex3f(420, 75, 410);
	glVertex3f(410, 75, 410);
	glVertex3f(410, 80, 410);
	glVertex3f(420, 80, 410);
	//right plane
	glVertex3f(410, 75, -410);
	glVertex3f(410, 80, -410);
	glVertex3f(410, 80, 410);
	glVertex3f(410, 75, 410);
	//left plane
	glVertex3f(420, 75, -410);
	glVertex3f(420, 80, -410);
	glVertex3f(420, 80, 410);
	glVertex3f(420, 75, 410);
	//top plane
	glVertex3f(420, 80, -410);
	glVertex3f(410, 80, -410);
	glVertex3f(410, 80, 410);
	glVertex3f(420, 80, 410);
	//bottom plane
	glVertex3f(410, 75, -410);
	glVertex3f(420, 75, -410);
	glVertex3f(420, 75, 410);
	glVertex3f(410, 75, 410);
	///----------------------------

	//---- top poll_z-i -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(-235, 75, -410);
	glVertex3f(-225, 75, -410);
	glVertex3f(-225, 80, -410);
	glVertex3f(-235, 80, -410);
	//front plane
	glVertex3f(-235, 75, 410);
	glVertex3f(-225, 75, 410);
	glVertex3f(-225, 80, 410);
	glVertex3f(-235, 80, 410);
	//right plane
	glVertex3f(-225, 75, -410);
	glVertex3f(-225, 80, -410);
	glVertex3f(-225, 80, 410);
	glVertex3f(-225, 75, 410);
	//left plane
	glVertex3f(-235, 75, -410);
	glVertex3f(-235, 80, -410);
	glVertex3f(-235, 80, 410);
	glVertex3f(-235, 75, 410);
	//top plane
	glVertex3f(-235, 80, -410);
	glVertex3f(-225, 80, -410);
	glVertex3f(-225, 80, 410);
	glVertex3f(-235, 80, 410);
	//bottom plane
	glVertex3f(-225, 75, -410);
	glVertex3f(-235, 75, -410);
	glVertex3f(-235, 75, 410);
	glVertex3f(-225, 75, 410);
	///----------------------------

	//---- top poll_z-ii -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(-5, 75, -100);
	glVertex3f(5, 75, -100);
	glVertex3f(5, 80, -100);
	glVertex3f(-5, 80, -100);
	//front plane
	glVertex3f(-5, 75, -420);
	glVertex3f(5, 75, -420);
	glVertex3f(5, 80, -420);
	glVertex3f(-5, 80, -420);
	//right plane
	glVertex3f(5, 75, -100);
	glVertex3f(5, 80, -100);
	glVertex3f(5, 80, -420);
	glVertex3f(5, 75, -420);
	//left plane
	glVertex3f(-5, 75, -100);
	glVertex3f(-5, 80, -100);
	glVertex3f(-5, 80, -420);
	glVertex3f(-5, 75, -420);
	//top plane
	glVertex3f(-5, 80, -100);
	glVertex3f(5, 80, -100);
	glVertex3f(5, 80, -420);
	glVertex3f(-5, 80, -420);
	//bottom plane
	glVertex3f(5, 75, -100);
	glVertex3f(-5, 75, -100);
	glVertex3f(-5, 75, -420);
	glVertex3f(5, 75, -420);
	///----------------------------

	//---- top poll_z-iii -----
	glColor3f(0.6, 0.6, 0.6);
	//back plane
	glVertex3f(235, 75, -410);
	glVertex3f(225, 75, -410);
	glVertex3f(225, 80, -410);
	glVertex3f(235, 80, -410);
	//front plane
	glVertex3f(235, 75, 410);
	glVertex3f(225, 75, 410);
	glVertex3f(225, 80, 410);
	glVertex3f(235, 80, 410);
	//right plane
	glVertex3f(225, 75, -410);
	glVertex3f(225, 80, -410);
	glVertex3f(225, 80, 410);
	glVertex3f(225, 75, 410);
	//left plane
	glVertex3f(235, 75, -410);
	glVertex3f(235, 80, -410);
	glVertex3f(235, 80, 410);
	glVertex3f(235, 75, 410);
	//top plane
	glVertex3f(235, 80, -410);
	glVertex3f(225, 80, -410);
	glVertex3f(225, 80, 410);
	glVertex3f(235, 80, 410);
	//bottom plane
	glVertex3f(225, 75, -410);
	glVertex3f(235, 75, -410);
	glVertex3f(235, 75, 410);
	glVertex3f(225, 75, 410);
	///----------------------------

	//------ front poll-i.i -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(-235, 75, -200);
	glVertex3f(-225, 75, -200);
	glVertex3f(-225, -75, -200);
	glVertex3f(-235, -75, -200);
	//front plane
	glVertex3f(-235, 75, -210);
	glVertex3f(-225, 75, -210);
	glVertex3f(-225, -75, -210);
	glVertex3f(-235, -75, -210);
	//right plane
	glVertex3f(-225, 75, -200);
	glVertex3f(-225, -75, -200);
	glVertex3f(-225, -75, -210);
	glVertex3f(-225, 75, -210);
	//left plane
	glVertex3f(-235, 75, -200);
	glVertex3f(-235, -75, -200);
	glVertex3f(-235, -75, -210);
	glVertex3f(-235, 75, -210);
	//top plane
	glVertex3f(-235, 75, -200);
	glVertex3f(-225, 75, -200);
	glVertex3f(-225, 75, -200);
	glVertex3f(-235, 75, -200);
	//bottom plane
	glVertex3f(-235, -75, -200);
	glVertex3f(-225, -75, -200);
	glVertex3f(-225, -75, -210);
	glVertex3f(-235, -75, -210);
	//-----------------------------

	//------ front poll-i.ii -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(-235, 75, -10);
	glVertex3f(-225, 75, -10);
	glVertex3f(-225, -75, -10);
	glVertex3f(-235, -75, -10);
	//front plane
	glVertex3f(-235, 75, 0);
	glVertex3f(-225, 75, 0);
	glVertex3f(-225, -75, 0);
	glVertex3f(-235, -75, 0);
	//right plane
	glVertex3f(-225, 75, -10);
	glVertex3f(-225, -75, -10);
	glVertex3f(-225, -75, 0);
	glVertex3f(-225, 75, 0);
	//left plane
	glVertex3f(-235, 75, -10);
	glVertex3f(-235, -75, -10);
	glVertex3f(-235, -75, 0);
	glVertex3f(-235, 75, 0);
	//top plane
	glVertex3f(-235, 75, -10);
	glVertex3f(-225, 75, -10);
	glVertex3f(-225, 75, 0);
	glVertex3f(-235, 75, 0);
	//bottom plane
	glVertex3f(-235, -75, -10);
	glVertex3f(-225, -75, -10);
	glVertex3f(-225, -75, 0);
	glVertex3f(-235, -75, 0);
	//-----------------------------

	//------ front poll-i.iii -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(-235, 75, 200);
	glVertex3f(-225, 75, 200);
	glVertex3f(-225, -75, 200);
	glVertex3f(-235, -75, 200);
	//front plane
	glVertex3f(-235, 75, 210);
	glVertex3f(-225, 75, 210);
	glVertex3f(-225, -75, 210);
	glVertex3f(-235, -75, 210);
	//right plane
	glVertex3f(-225, 75, 200);
	glVertex3f(-225, -75, 200);
	glVertex3f(-225, -75, 210);
	glVertex3f(-225, 75, 210);
	//left plane
	glVertex3f(-235, 75, 200);
	glVertex3f(-235, -75, 200);
	glVertex3f(-235, -75, 210);
	glVertex3f(-235, 75, 210);
	//top plane
	glVertex3f(-235, 75, 200);
	glVertex3f(-225, 75, 200);
	glVertex3f(-225, 75, 200);
	glVertex3f(-235, 75, 200);
	//bottom plane
	glVertex3f(-235, -75, 200);
	glVertex3f(-225, -75, 200);
	glVertex3f(-225, -75, 210);
	glVertex3f(-235, -75, 210);
	//-----------------------------

	//------ front poll-i.iv -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(-235, 75, 410);
	glVertex3f(-225, 75, 410);
	glVertex3f(-225, -75, 410);
	glVertex3f(-235, -75, 410);
	//front plane
	glVertex3f(-235, 75, 420);
	glVertex3f(-225, 75, 420);
	glVertex3f(-225, -75, 420);
	glVertex3f(-235, -75, 420);
	//right plane
	glVertex3f(-225, 75, 410);
	glVertex3f(-225, -75, 410);
	glVertex3f(-225, -75, 420);
	glVertex3f(-225, 75, 420);
	//left plane
	glVertex3f(-235, 75, 410);
	glVertex3f(-235, -75, 410);
	glVertex3f(-235, -75, 420);
	glVertex3f(-235, 75, 420);
	//top plane
	glVertex3f(-235, 75, 410);
	glVertex3f(-225, 75, 410);
	glVertex3f(-225, 75, 420);
	glVertex3f(-235, 75, 420);
	//bottom plane
	glVertex3f(-235, -75, 410);
	glVertex3f(-225, -75, 410);
	glVertex3f(-225, -75, 420);
	glVertex3f(-235, -75, 420);
	//-----------------------------

	//------ front poll-ii.i -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(235, 75, -200);
	glVertex3f(225, 75, -200);
	glVertex3f(225, -75, -200);
	glVertex3f(235, -75, -200);
	//front plane
	glVertex3f(235, 75, -210);
	glVertex3f(225, 75, -210);
	glVertex3f(225, -75, -210);
	glVertex3f(235, -75, -210);
	//right plane
	glVertex3f(225, 75, -200);
	glVertex3f(225, -75, -200);
	glVertex3f(225, -75, -210);
	glVertex3f(225, 75, -210);
	//left plane
	glVertex3f(235, 75, -200);
	glVertex3f(235, -75, -200);
	glVertex3f(235, -75, -210);
	glVertex3f(235, 75, -210);
	//top plane
	glVertex3f(235, 75, -200);
	glVertex3f(225, 75, -200);
	glVertex3f(225, 75, -200);
	glVertex3f(235, 75, -200);
	//bottom plane
	glVertex3f(235, -75, -200);
	glVertex3f(225, -75, -200);
	glVertex3f(225, -75, -210);
	glVertex3f(235, -75, -210);
	//-----------------------------

	//------ front poll-ii.ii -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(235, 75, -10);
	glVertex3f(225, 75, -10);
	glVertex3f(225, -75, -10);
	glVertex3f(235, -75, -10);
	//front plane
	glVertex3f(235, 75, 0);
	glVertex3f(225, 75, 0);
	glVertex3f(225, -75, 0);
	glVertex3f(235, -75, 0);
	//right plane
	glVertex3f(225, 75, -10);
	glVertex3f(225, -75, -10);
	glVertex3f(225, -75, 0);
	glVertex3f(225, 75, 0);
	//left plane
	glVertex3f(235, 75, -10);
	glVertex3f(235, -75, -10);
	glVertex3f(235, -75, 0);
	glVertex3f(235, 75, 0);
	//top plane
	glVertex3f(235, 75, -10);
	glVertex3f(225, 75, -10);
	glVertex3f(225, 75, 0);
	glVertex3f(235, 75, 0);
	//bottom plane
	glVertex3f(235, -75, -10);
	glVertex3f(225, -75, -10);
	glVertex3f(225, -75, 0);
	glVertex3f(235, -75, 0);
	//-----------------------------

	//------ front poll-ii.iii -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(235, 75, 200);
	glVertex3f(225, 75, 200);
	glVertex3f(225, -75, 200);
	glVertex3f(235, -75, 200);
	//front plane
	glVertex3f(235, 75, 210);
	glVertex3f(225, 75, 210);
	glVertex3f(225, -75, 210);
	glVertex3f(235, -75, 210);
	//right plane
	glVertex3f(225, 75, 200);
	glVertex3f(225, -75, 200);
	glVertex3f(225, -75, 210);
	glVertex3f(225, 75, 210);
	//left plane
	glVertex3f(235, 75, 200);
	glVertex3f(235, -75, 200);
	glVertex3f(235, -75, 210);
	glVertex3f(235, 75, 210);
	//top plane
	glVertex3f(235, 75, 200);
	glVertex3f(225, 75, 200);
	glVertex3f(225, 75, 200);
	glVertex3f(235, 75, 200);
	//bottom plane
	glVertex3f(235, -75, 200);
	glVertex3f(225, -75, 200);
	glVertex3f(225, -75, 210);
	glVertex3f(235, -75, 210);
	//-----------------------------

	//------ front poll-ii.iv -------
	glColor3f(0.7, 0.7, 0.7);
	//back plane
	glVertex3f(235, 75, 410);
	glVertex3f(225, 75, 410);
	glVertex3f(225, -75, 410);
	glVertex3f(235, -75, 410);
	//front plane
	glVertex3f(235, 75, 420);
	glVertex3f(225, 75, 420);
	glVertex3f(225, -75, 420);
	glVertex3f(235, -75, 420);
	//right plane
	glVertex3f(225, 75, 410);
	glVertex3f(225, -75, 410);
	glVertex3f(225, -75, 420);
	glVertex3f(225, 75, 420);
	//left plane
	glVertex3f(235, 75, 410);
	glVertex3f(235, -75, 410);
	glVertex3f(235, -75, 420);
	glVertex3f(235, 75, 420);
	//top plane
	glVertex3f(235, 75, 410);
	glVertex3f(225, 75, 410);
	glVertex3f(225, 75, 420);
	glVertex3f(235, 75, 420);
	//bottom plane
	glVertex3f(235, -75, 410);
	glVertex3f(225, -75, 410);
	glVertex3f(225, -75, 420);
	glVertex3f(235, -75, 420);
	//-----------------------------
	glEnd();

	///////////// poll ends /////////////

	///////////// chair starts /////////////
	//------ chair stand -------
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	//back plane
	glVertex3f(-350, -60, 250);
	glVertex3f(-300, -60, 250);
	glVertex3f(-300, -75, 250);
	glVertex3f(-350, -75, 250);
	//front plane
	glVertex3f(-350, -60, 320);
	glVertex3f(-300, -60, 320);
	glVertex3f(-300, -75, 320);
	glVertex3f(-350, -75, 320);

	glColor3f(0.6, 0.6, 0.6);
	//right plane
	glVertex3f(-300, -60, 250);
	glVertex3f(-300, -75, 250);
	glVertex3f(-300, -75, 320);
	glVertex3f(-300, -60, 320);
	//left plane
	glVertex3f(-350, -60, 250);
	glVertex3f(-350, -75, 250);
	glVertex3f(-350, -75, 320);
	glVertex3f(-350, -60, 320);
	//top plane
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-350, -60, 250);
	glVertex3f(-300, -60, 250);
	glVertex3f(-300, -60, 320);
	glVertex3f(-350, -60, 320);
	//bottom plane		
	glVertex3f(-350, -75, 250);
	glVertex3f(-300, -75, 250);
	glVertex3f(-300, -75, 320);
	glVertex3f(-350, -75, 320);
	//-----------------------------

	//------------The chair -----------

	//== front left leg ==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-340, -40, 308.5);
	glVertex3f(-338.5, -40, 308.5);
	glVertex3f(-338.5, -60, 308.5);
	glVertex3f(-340, -60, 308.5);
	//front plane		
	glVertex3f(-340, -40, 310);
	glVertex3f(-338.5, -40, 310);
	glVertex3f(-338.5, -60, 310);
	glVertex3f(-340, -60, 310);

	glColor3f(0.5, 0.5, 0.5);
	//right plane		
	glVertex3f(-338.5, -40, 308.5);
	glVertex3f(-338.5, -60, 308.5);
	glVertex3f(-338.5, -60, 310);
	glVertex3f(-338.5, -40, 310);
	//left plane
	glVertex3f(-340, -40, 308.5);
	glVertex3f(-340, -60, 308.5);
	glVertex3f(-340, -60, 310);
	glVertex3f(-340, -40, 310);

	glColor3f(1.0, 1.0, 1.0);
	//top plane
	glVertex3f(-340, -40, 308.5);
	glVertex3f(-338.5, -40, 308.5);
	glVertex3f(-338.5, -40, 310);
	glVertex3f(-340, -40, 310);
	//bottom plane		
	glVertex3f(-340, -60, 308.5);
	glVertex3f(-338.5, -60, 308.5);
	glVertex3f(-338.5, -60, 310);
	glVertex3f(-340, -60, 310);
	//================================

	//== front right leg ==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-310, -40, 308.5);
	glVertex3f(-311.5, -40, 308.5);
	glVertex3f(-311.5, -60, 308.5);
	glVertex3f(-310, -60, 308.5);
	//front plane		
	glVertex3f(-310, -40, 310);
	glVertex3f(-311.5, -40, 310);
	glVertex3f(-311.5, -60, 310);
	glVertex3f(-310, -60, 310);

	glColor3f(0.5, 0.5, 0.5);
	//right plane		
	glVertex3f(-311.5, -40, 308.5);
	glVertex3f(-311.5, -60, 308.5);
	glVertex3f(-311.5, -60, 310);
	glVertex3f(-311.5, -40, 310);
	//left plane
	glVertex3f(-310, -40, 308.5);
	glVertex3f(-310, -60, 308.5);
	glVertex3f(-310, -60, 310);
	glVertex3f(-310, -40, 310);

	glColor3f(1.0, 1.0, 1.0);
	//top plane
	glVertex3f(-310, -40, 308.5);
	glVertex3f(-311.5, -40, 308.5);
	glVertex3f(-311.5, -40, 310);
	glVertex3f(-310, -40, 310);
	//bottom plane		
	glVertex3f(-310, -60, 308.5);
	glVertex3f(-311.5, -60, 308.5);
	glVertex3f(-311.5, -60, 310);
	glVertex3f(-310, -60, 310);
	////================================

	//== back left leg ==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-340, -30, 271.5);
	glVertex3f(-338.5, -30, 271.5);
	glVertex3f(-338.5, -60, 271.5);
	glVertex3f(-340, -60, 271.5);
	//front plane		
	glVertex3f(-340, -30, 270);
	glVertex3f(-338.5, -30, 270);
	glVertex3f(-338.5, -60, 270);
	glVertex3f(-340, -60, 270);

	glColor3f(0.5, 0.5, 0.5);
	//right plane		
	glVertex3f(-338.5, -30, 271.5);
	glVertex3f(-338.5, -60, 271.5);
	glVertex3f(-338.5, -60, 270);
	glVertex3f(-338.5, -30, 270);
	//left plane
	glVertex3f(-340, -30, 271.5);
	glVertex3f(-340, -60, 271.5);
	glVertex3f(-340, -60, 270);
	glVertex3f(-340, -30, 270);

	glColor3f(1.0, 1.0, 1.0);
	//top plane
	glVertex3f(-340, -30, 271.5);
	glVertex3f(-338.5, -30, 271.5);
	glVertex3f(-338.5, -30, 270);
	glVertex3f(-340, -30, 270);
	//bottom plane		
	glVertex3f(-340, -60, 271.5);
	glVertex3f(-338.5, -60, 271.5);
	glVertex3f(-338.5, -60, 270);
	glVertex3f(-340, -60, 270);
	//================================

	//== back left leg front==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-340, -30, 281.5);
	glVertex3f(-338.5, -30, 281.5);
	glVertex3f(-338.5, -60, 281.5);
	glVertex3f(-340, -60, 281.5);
	//front plane		
	glVertex3f(-340, -30, 280);
	glVertex3f(-338.5, -30, 280);
	glVertex3f(-338.5, -60, 280);
	glVertex3f(-340, -60, 280);

	glColor3f(0.5, 0.5, 0.5);
	//right plane		
	glVertex3f(-338.5, -30, 281.5);
	glVertex3f(-338.5, -60, 281.5);
	glVertex3f(-338.5, -60, 280);
	glVertex3f(-338.5, -30, 280);
	//left plane
	glVertex3f(-340, -30, 281.5);
	glVertex3f(-340, -60, 281.5);
	glVertex3f(-340, -60, 280);
	glVertex3f(-340, -30, 280);

	glColor3f(1.0, 1.0, 1.0);
	//top plane
	glVertex3f(-340, -30, 281.5);
	glVertex3f(-338.5, -30, 281.5);
	glVertex3f(-338.5, -30, 280);
	glVertex3f(-340, -30, 280);
	//bottom plane		
	glVertex3f(-340, -60, 281.5);
	glVertex3f(-338.5, -60, 281.5);
	glVertex3f(-338.5, -60, 280);
	glVertex3f(-340, -60, 280);
	//================================

	//== back right leg ==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-310, -30, 271.5);
	glVertex3f(-311.5, -30, 271.5);
	glVertex3f(-311.5, -60, 271.5);
	glVertex3f(-310, -60, 271.5);
	//front plane		
	glVertex3f(-310, -30, 270);
	glVertex3f(-311.5, -30, 270);
	glVertex3f(-311.5, -60, 270);
	glVertex3f(-310, -60, 270);

	glColor3f(0.5, 0.5, 0.5);
	//right plane		
	glVertex3f(-311.5, -30, 271.5);
	glVertex3f(-311.5, -60, 271.5);
	glVertex3f(-311.5, -60, 270);
	glVertex3f(-311.5, -30, 270);
	//left plane
	glVertex3f(-310, -30, 271.5);
	glVertex3f(-310, -60, 271.5);
	glVertex3f(-310, -60, 270);
	glVertex3f(-310, -30, 270);

	glColor3f(1.0, 1.0, 1.0);
	//top plane
	glVertex3f(-310, -30, 271.5);
	glVertex3f(-311.5, -30, 271.5);
	glVertex3f(-311.5, -30, 270);
	glVertex3f(-310, -30, 270);
	//bottom plane		
	glVertex3f(-310, -60, 271.5);
	glVertex3f(-311.5, -60, 271.5);
	glVertex3f(-311.5, -60, 270);
	glVertex3f(-310, -60, 270);
	//================================

	//== back right leg front==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-310, -30, 281.5);
	glVertex3f(-311.5, -30, 281.5);
	glVertex3f(-311.5, -60, 281.5);
	glVertex3f(-310, -60, 281.5);
	//front plane		
	glVertex3f(-310, -30, 280);
	glVertex3f(-311.5, -30, 280);
	glVertex3f(-311.5, -60, 280);
	glVertex3f(-310, -60, 280);

	glColor3f(0.5, 0.5, 0.5);
	//right plane
	glVertex3f(-311.5, -30, 281.5);
	glVertex3f(-311.5, -60, 281.5);
	glVertex3f(-311.5, -60, 280);
	glVertex3f(-311.5, -30, 280);
	//left plane
	glVertex3f(-310, -30, 281.5);
	glVertex3f(-310, -60, 281.5);
	glVertex3f(-310, -60, 280);
	glVertex3f(-310, -30, 280);

	glColor3f(1.0, 1.0, 1.0);
	//top plane
	glVertex3f(-310, -30, 281.5);
	glVertex3f(-311.5, -30, 281.5);
	glVertex3f(-311.5, -30, 280);
	glVertex3f(-310, -30, 280);
	//bottom plane		
	glVertex3f(-310, -60, 281.5);
	glVertex3f(-311.5, -60, 281.5);
	glVertex3f(-311.5, -60, 280);
	glVertex3f(-310, -60, 280);
	//================================

	//== front leg connector bottom==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-341, -56.5, 307);
	glVertex3f(-309, -56.5, 307);
	glVertex3f(-309, -55, 307);
	glVertex3f(-341, -55, 307);
	//front plane
	glVertex3f(-341, -56.5, 308.5);
	glVertex3f(-309, -56.5, 308.5);
	glVertex3f(-309, -55, 308.5);
	glVertex3f(-341, -55, 308.5);

	glColor3f(1.0, 1.0, 1.0);
	//right plane
	glVertex3f(-309, -56.5, 307);
	glVertex3f(-309, -55, 307);
	glVertex3f(-309, -55, 308.5);
	glVertex3f(-309, -56.5, 308.5);
	//left plane
	glVertex3f(-341, -56.5, 307);
	glVertex3f(-341, -55, 307);
	glVertex3f(-341, -55, 308.5);
	glVertex3f(-341, -56.5, 308.5);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-341, -56.5, 307);
	glVertex3f(-309, -56.5, 307);
	glVertex3f(-309, -56.5, 308.5);
	glVertex3f(-341, -56.5, 308.5);
	//bottom plane		
	glVertex3f(-341, -55, 307);
	glVertex3f(-309, -55, 307);
	glVertex3f(-309, -55, 308.5);
	glVertex3f(-341, -55, 308.5);
	//================================

	//== front leg connector top==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-341, -43.5, 307);
	glVertex3f(-309, -43.5, 307);
	glVertex3f(-309, -45, 307);
	glVertex3f(-341, -45, 307);
	//front plane		
	glVertex3f(-341, -43.5, 308.5);
	glVertex3f(-309, -43.5, 308.5);
	glVertex3f(-309, -45, 308.5);
	glVertex3f(-341, -45, 308.5);

	glColor3f(1.0, 1.0, 1.0);
	//right plane
	glVertex3f(-309, -43.5, 307);
	glVertex3f(-309, -45, 307);
	glVertex3f(-309, -45, 308.5);
	glVertex3f(-309, -43.5, 308.5);
	//left plane
	glVertex3f(-341, -43.5, 307);
	glVertex3f(-341, -45, 307);
	glVertex3f(-341, -45, 308.5);
	glVertex3f(-341, -43.5, 308.5);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-341, -43.5, 307);
	glVertex3f(-309, -43.5, 307);
	glVertex3f(-309, -43.5, 308.5);
	glVertex3f(-341, -43.5, 308.5);
	//bottom plane		
	glVertex3f(-341, -45, 307);
	glVertex3f(-309, -45, 307);
	glVertex3f(-309, -45, 308.5);
	glVertex3f(-341, -45, 308.5);
	//================================

	//== back leg connector bottom==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-341, -56.5, 273);
	glVertex3f(-309, -56.5, 273);
	glVertex3f(-309, -55, 273);
	glVertex3f(-341, -55, 273);
	//front plane		
	glVertex3f(-341, -56.5, 271.5);
	glVertex3f(-309, -56.5, 271.5);
	glVertex3f(-309, -55, 271.5);
	glVertex3f(-341, -55, 271.5);

	glColor3f(1.0, 1.0, 1.0);
	//right plane		
	glVertex3f(-309, -56.5, 273);
	glVertex3f(-309, -55, 273);
	glVertex3f(-309, -55, 271.5);
	glVertex3f(-309, -56.5, 271.5);
	//left plane
	glVertex3f(-341, -56.5, 273);
	glVertex3f(-341, -55, 273);
	glVertex3f(-341, -55, 271.5);
	glVertex3f(-341, -56.5, 271.5);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-341, -56.5, 273);
	glVertex3f(-309, -56.5, 273);
	glVertex3f(-309, -56.5, 271.5);
	glVertex3f(-341, -56.5, 271.5);
	//bottom plane		
	glVertex3f(-341, -55, 273);
	glVertex3f(-309, -55, 273);
	glVertex3f(-309, -55, 271.5);
	glVertex3f(-341, -55, 271.5);
	//================================

	//== back leg connector top==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-344, -31.5, 273);
	glVertex3f(-306, -31.5, 273);
	glVertex3f(-306, -30, 273);
	glVertex3f(-344, -30, 273);
	//front plane
	glVertex3f(-344, -31.5, 271.5);
	glVertex3f(-306, -31.5, 271.5);
	glVertex3f(-306, -30, 271.5);
	glVertex3f(-344, -30, 271.5);

	glColor3f(1.0, 1.0, 1.0);
	//right plane
	glVertex3f(-306, -31.5, 273);
	glVertex3f(-306, -30, 273);
	glVertex3f(-306, -30, 271.5);
	glVertex3f(-306, -31.5, 271.5);
	//left plane
	glVertex3f(-344, -31.5, 273);
	glVertex3f(-344, -30, 273);
	glVertex3f(-344, -30, 271.5);
	glVertex3f(-344, -31.5, 271.5);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-344, -31.5, 273);
	glVertex3f(-306, -31.5, 273);
	glVertex3f(-306, -31.5, 271.5);
	glVertex3f(-344, -31.5, 271.5);
	//bottom plane		
	glVertex3f(-344, -30, 273);
	glVertex3f(-306, -30, 273);
	glVertex3f(-306, -30, 271.5);
	glVertex3f(-344, -30, 271.5);
	//================================

	//== back-front leg connector==========
	glColor3f(0.3, 0.3, 0.3);
	//back plane
	glVertex3f(-341, -47, 283);
	glVertex3f(-309, -47, 283);
	glVertex3f(-309, -48, 283);
	glVertex3f(-341, -48, 283);
	//front plane
	glVertex3f(-341, -47, 281.5);
	glVertex3f(-309, -47, 281.5);
	glVertex3f(-309, -48, 281.5);
	glVertex3f(-341, -48, 281.5);

	glColor3f(1.0, 1.0, 1.0);
	//right plane
	glVertex3f(-309, -47, 283);
	glVertex3f(-309, -48, 283);
	glVertex3f(-309, -48, 281.5);
	glVertex3f(-309, -47, 281.5);
	//left plane
	glVertex3f(-341, -47, 283);
	glVertex3f(-341, -48, 283);
	glVertex3f(-341, -48, 281.5);
	glVertex3f(-341, -47, 281.5);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-341, -47, 283);
	glVertex3f(-309, -47, 283);
	glVertex3f(-309, -47, 281.5);
	glVertex3f(-341, -47, 281.5);
	//bottom plane		
	glVertex3f(-341, -48, 283);
	glVertex3f(-309, -48, 283);
	glVertex3f(-309, -48, 281.5);
	glVertex3f(-341, -48, 281.5);
	//================================

	//== left legs connector==========
	glColor3f(1.0, 1.0, 1.0);
	//back plane
	glVertex3f(-338.5, -56.5, 269);
	glVertex3f(-337, -56.5, 269);
	glVertex3f(-337, -58, 269);
	glVertex3f(-338.5, -58, 269);
	//front plane
	glVertex3f(-338.5, -56.5, 311);
	glVertex3f(-337, -56.5, 311);
	glVertex3f(-337, -58, 311);
	glVertex3f(-338.5, -58, 311);

	glColor3f(0.5, 0.5, 0.5);
	//right plane
	glVertex3f(-337, -56.5, 269);
	glVertex3f(-337, -58, 269);
	glVertex3f(-337, -58, 311);
	glVertex3f(-337, -56.5, 311);
	//left plane
	glVertex3f(-338.5, -56.5, 269);
	glVertex3f(-338.5, -58, 269);
	glVertex3f(-338.5, -58, 311);
	glVertex3f(-338.5, -56.5, 311);

	glColor3f(0.3, 0.3, 0.3);
	//top plane
	glVertex3f(-338.5, -56.5, 269);
	glVertex3f(-337, -56.5, 269);
	glVertex3f(-337, -56.5, 311);
	glVertex3f(-338.5, -56.5, 311);
	//bottom plane		
	glVertex3f(-338.5, -58, 269);
	glVertex3f(-337, -58, 269);
	glVertex3f(-337, -58, 311);
	glVertex3f(-338.5, -58, 311);
	//================================

	//== right legs connector==========
	glColor3f(1.0, 1.0, 1.0);
	//back plane
	glVertex3f(-311.5, -56.5, 269);
	glVertex3f(-313, -56.5, 269);
	glVertex3f(-313, -58, 269);
	glVertex3f(-311.5, -58, 269);
	//front plane
	glVertex3f(-311.5, -56.5, 311);
	glVertex3f(-313, -56.5, 311);
	glVertex3f(-313, -58, 311);
	glVertex3f(-311.5, -58, 311);

	glColor3f(0.5, 0.5, 0.5);
	//right plane
	glVertex3f(-313, -56.5, 269);
	glVertex3f(-313, -58, 269);
	glVertex3f(-313, -58, 311);
	glVertex3f(-313, -56.5, 311);
	//left plane
	glVertex3f(-311.5, -56.5, 269);
	glVertex3f(-311.5, -58, 269);
	glVertex3f(-311.5, -58, 311);
	glVertex3f(-311.5, -56.5, 311);

	glColor3f(0.3, 0.3, 0.3);
	//top plane
	glVertex3f(-311.5, -56.5, 269);
	glVertex3f(-313, -56.5, 269);
	glVertex3f(-313, -56.5, 311);
	glVertex3f(-311.5, -56.5, 311);
	//bottom plane		
	glVertex3f(-311.5, -58, 269);
	glVertex3f(-313, -58, 269);
	glVertex3f(-313, -58, 311);
	glVertex3f(-311.5, -58, 311);
	//================================

	//== chair seat==========
	glColor3f(0.4, 0.4, 0.4);
	//front plane
	glVertex3f(-337, -43, 315);
	glVertex3f(-313, -43, 315);
	glVertex3f(-313, -42, 315);
	glVertex3f(-337, -42, 315);
	//back plane
	glVertex3f(-337, -46, 281.5);
	glVertex3f(-313, -46, 281.5);
	glVertex3f(-313, -47, 281.5);
	glVertex3f(-337, -47, 281.5);

	glColor3f(0.5, 0.5, 0.5);

	//right plane
	glVertex3f(-313, -43, 315);
	glVertex3f(-313, -42, 315);
	glVertex3f(-313, -47, 281.5);
	glVertex3f(-313, -46, 281.5);
	//left plane
	glVertex3f(-337, -43, 315);
	glVertex3f(-337, -42, 315);
	glVertex3f(-337, -47, 281.5);
	glVertex3f(-337, -46, 281.5);

	glColor3f(0.7, 0.7, 0.7);
	//top plane
	glVertex3f(-337, -43, 315);
	glVertex3f(-313, -43, 315);
	glVertex3f(-313, -46, 281.5);
	glVertex3f(-337, -46, 281.5);
	//bottom plane		
	glVertex3f(-337, -42, 315);
	glVertex3f(-313, -42, 315);
	glVertex3f(-313, -47, 281.5);
	glVertex3f(-337, -47, 281.5);
	//================================

	//== chair back plane ==========
	glColor3f(1.0, 0.1, 0.2);
	//back plane
	glVertex3f(-317.5, -10, 265);
	glVertex3f(-333.5, -10, 265);
	glVertex3f(-333.5, -55, 283);
	glVertex3f(-317.5, -55, 283);
	//front plane
	glVertex3f(-317.5, -10, 266);
	glVertex3f(-333.5, -10, 266);
	glVertex3f(-333.5, -55, 284);
	glVertex3f(-317.5, -55, 284);

	glColor3f(0.3, 0.3, 0.3);
	//right plane
	glVertex3f(-333.5, -10, 265);
	glVertex3f(-333.5, -55, 283);
	glVertex3f(-333.5, -55, 284);
	glVertex3f(-333.5, -10, 266);
	//left plane
	glVertex3f(-317.5, -10, 265);
	glVertex3f(-317.5, -55, 283);
	glVertex3f(-317.5, -55, 284);
	glVertex3f(-317.5, -10, 266);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-317.5, -10, 265);
	glVertex3f(-333.5, -10, 265);
	glVertex3f(-333.5, -10, 266);
	glVertex3f(-317.5, -10, 266);
	//bottom plane		
	glVertex3f(-317.5, -55, 283);
	glVertex3f(-333.5, -55, 283);
	glVertex3f(-333.5, -55, 284);
	glVertex3f(-317.5, -55, 284);
	//================================


	//== chair hand left ==========
	glColor3f(1.0, 1.0, 1.0);
	//back plane
	glVertex3f(-342, -28.5, 288);
	glVertex3f(-336, -28.5, 288);
	glVertex3f(-336, -30, 288);
	glVertex3f(-342, -30, 288);
	//front plane
	glVertex3f(-342, -28.5, 269);
	glVertex3f(-336, -28.5, 269);
	glVertex3f(-336, -30, 269);
	glVertex3f(-342, -30, 269);

	glColor3f(0.3, 0.3, 0.3);
	//right plane
	glVertex3f(-336, -28.5, 288);
	glVertex3f(-336, -30, 288);
	glVertex3f(-336, -30, 269);
	glVertex3f(-336, -28.5, 269);
	//left plane
	glVertex3f(-342, -28.5, 288);
	glVertex3f(-342, -30, 288);
	glVertex3f(-342, -30, 269);
	glVertex3f(-342, -28.5, 269);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-342, -28.5, 288);
	glVertex3f(-336, -28.5, 288);
	glVertex3f(-336, -28.5, 269);
	glVertex3f(-342, -28.5, 269);
	//bottom plane		
	glVertex3f(-342, -30, 288);
	glVertex3f(-336, -30, 288);
	glVertex3f(-336, -30, 269);
	glVertex3f(-342, -30, 269);
	//================================

	//== chair hand right ==========
	glColor3f(1.0, 1.0, 1.0);
	//back plane
	glVertex3f(-308, -28.5, 288);
	glVertex3f(-314, -28.5, 288);
	glVertex3f(-314, -30, 288);
	glVertex3f(-308, -30, 288);
	//front plane
	glVertex3f(-308, -28.5, 269);
	glVertex3f(-314, -28.5, 269);
	glVertex3f(-314, -30, 269);
	glVertex3f(-308, -30, 269);

	glColor3f(0.3, 0.3, 0.3);
	//right plane
	glVertex3f(-314, -28.5, 288);
	glVertex3f(-314, -30, 288);
	glVertex3f(-314, -30, 269);
	glVertex3f(-314, -28.5, 269);
	//left plane
	glVertex3f(-308, -28.5, 288);
	glVertex3f(-308, -30, 288);
	glVertex3f(-308, -30, 269);
	glVertex3f(-308, -28.5, 269);

	glColor3f(0.5, 0.5, 0.5);
	//top plane
	glVertex3f(-308, -28.5, 288);
	glVertex3f(-314, -28.5, 288);
	glVertex3f(-314, -28.5, 269);
	glVertex3f(-308, -28.5, 269);
	//bottom plane		
	glVertex3f(-308, -30, 288);
	glVertex3f(-314, -30, 288);
	glVertex3f(-314, -30, 269);
	glVertex3f(-308, -30, 269);
	//================================

	glEnd();
	///////////// chair ends /////////////

	///////////// mini-table starts /////////////

	float mt_x = -235, mt_width = 20;
	float mt_y = -66, mt_thickness = 2;
	float mt_z = -200;
	float mt_inside = 1, mt_leg_width = 2.5;
	float mt_ground = -75;

	glBegin(GL_QUADS);
	for (int i = 1, count = 1; i <= 18; i++, count++)
	{
		if (count == 18)
		{
			mt_x = 225;
			mt_z = -200;
			i = 1;
		}
		mt_z += 10;
		if (i != 7 && i != 14)
		{
			//-------------top plane--------------------------------------
			glColor3f(0.7, 0.7, 0.7);
			//back plane
			glVertex3f(mt_x, mt_y, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y + mt_thickness, mt_z + mt_width);
			glVertex3f(mt_x, mt_y + mt_thickness, mt_z + mt_width);
			//front plane
			glVertex3f(mt_x, mt_y, mt_z);
			glVertex3f(mt_x + mt_width, mt_y, mt_z);
			glVertex3f(mt_x + mt_width, mt_y + mt_thickness, mt_z);
			glVertex3f(mt_x, mt_y + mt_thickness, mt_z);
			glColor3f(0.9, 0.9, 0.9);
			//right plane
			glVertex3f(mt_x + mt_width, mt_y, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y + mt_thickness, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y + mt_thickness, mt_z);
			glVertex3f(mt_x + mt_width, mt_y, mt_z);
			//left plane
			glVertex3f(mt_x, mt_y, mt_z + mt_width);
			glVertex3f(mt_x, mt_y + mt_thickness, mt_z + mt_width);
			glVertex3f(mt_x, mt_y + mt_thickness, mt_z);
			glVertex3f(mt_x, mt_y, mt_z);
			glColor3f(0.8, 0.8, 0.8);
			//top plane
			glVertex3f(mt_x, mt_y, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y, mt_z);
			glVertex3f(mt_x, mt_y, mt_z);
			//bottom plane
			glVertex3f(mt_x, mt_y + mt_thickness, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y + mt_thickness, mt_z + mt_width);
			glVertex3f(mt_x + mt_width, mt_y + mt_thickness, mt_z);
			glVertex3f(mt_x, mt_y + mt_thickness, mt_z);
			//---------------------------------------------------------------------------------------

			//-------------front left leg----------------------------------------------------------------
			glColor3f(0.8, 0.8, 0.8);
			//back plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_width - mt_inside);
			//front plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			//right plane
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			//left plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			//top plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			//bottom plane
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			//------------------------------------------------------------------------------

			//-------------front right leg----------------------------------------------------------------
			glColor3f(0.8, 0.8, 0.8);
			//back plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_width - mt_inside);
			//front plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			//right plane
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			//left plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			//top plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_width - mt_inside - mt_leg_width);
			//bottom plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_width - mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_width - mt_inside - mt_leg_width);
			//--------------------------------------------------------------------------------------------------------

			//-------------back left leg----------------------------------------------------------------
			glColor3f(0.8, 0.8, 0.8);
			//back plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_inside);
			//front plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_inside + mt_leg_width);
			//right plane
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_inside + mt_leg_width);
			//left plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_inside + mt_leg_width);
			//top plane
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_ground, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_ground, mt_z + mt_inside + mt_leg_width);
			//bottom plane
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_leg_width, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_inside, mt_y, mt_z + mt_inside + mt_leg_width);
			//------------------------------------------------------------------------------

			//-------------back right leg----------------------------------------------------------------
			glColor3f(0.8, 0.8, 0.8);
			//back plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_inside);
			//front plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_inside + mt_leg_width);
			//right plane
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_inside + mt_leg_width);
			//left plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_inside + mt_leg_width);
			//top plane				
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_ground, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_ground, mt_z + mt_inside + mt_leg_width);
			//bottom plane
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_inside);
			glVertex3f(mt_x + mt_width - mt_leg_width, mt_y, mt_z + mt_inside + mt_leg_width);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y, mt_z + mt_inside + mt_leg_width);
			//------------------------------------------------------------------------------

			//-------------front connector----------------------------------------------------------------
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z + mt_width - mt_inside - mt_leg_width / 3);

			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width / 2, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width / 2, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width, mt_z + mt_width - mt_inside - mt_leg_width / 3);

			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z + mt_width - mt_inside - mt_leg_width / 3);
			//-----------------------------------------------------------------------------

			//-------------back connector----------------------------------------------------------------
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z + mt_inside + mt_leg_width / 3);

			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width / 2, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width / 2, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 0) - mt_leg_width, mt_z + mt_inside + mt_leg_width / 3);

			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_width - mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z + mt_inside + mt_leg_width / 3);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z + mt_inside + mt_leg_width / 3);
			//-------------------------------------------------------------------------------------------------

			//-------------left connector----------------------------------------------------------------
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z + mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z + mt_inside);

			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 0) - mt_leg_width / 2, mt_z + mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 0) - mt_leg_width / 2, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 0) - mt_leg_width, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness - 0) - mt_leg_width, mt_z + mt_inside);

			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z + mt_inside);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x + mt_inside, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z + mt_inside);
			//-------------------------------------------------------------------------------------------------

			//-------------right connector----------------------------------------------------------------
			glColor3f(0.5, 0.5, 0.5);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z + mt_inside);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 2) - mt_leg_width / 2, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 2) - mt_leg_width, mt_z + mt_inside);

			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 0) - mt_leg_width / 2, mt_z + mt_inside);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 0) - mt_leg_width / 2, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 0) - mt_leg_width, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness - 0) - mt_leg_width, mt_z + mt_inside);

			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z + mt_inside);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness + 2) - mt_leg_width / 2, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z - mt_inside + mt_width);
			glVertex3f(mt_x - mt_inside + mt_width, mt_y - (mt_thickness + 2) - mt_leg_width, mt_z + mt_inside);
			//-----------------------------------------------------------------------------
		}
		mt_z += 20;
	}
	glEnd();
	///////////// mini-table ends /////////////

	///////////// top design starts /////////////

	float pos_x = -410, width = 85;
	float pos_y = 75, thickness = 1, angle = 10;
	float pos_z = -400, height = 10;

	glBegin(GL_QUADS);
	for (int j = 1; j <= 33; j++)
	{
		for (int i = 1; i <= 9; i = i++)
		{
			pos_x += 5;
			//----------------straight one------------------
			glColor3f(0.8, 0.8, 0.8);
			//back plane
			glVertex3f(pos_x, pos_y, pos_z - height);
			glVertex3f(pos_x + width, pos_y, pos_z - height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z - height);
			glVertex3f(pos_x, pos_y - thickness, pos_z - height);
			//front plane
			glVertex3f(pos_x, pos_y, pos_z);
			glVertex3f(pos_x + width, pos_y, pos_z);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z);
			glVertex3f(pos_x, pos_y - thickness, pos_z);

			glColor3f(0.8, 0.8, 0.8);
			//right plane
			glVertex3f(pos_x + width, pos_y, pos_z);
			glVertex3f(pos_x + width, pos_y, pos_z - height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z - height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z);
			//left plane
			glVertex3f(pos_x, pos_y, pos_z);
			glVertex3f(pos_x, pos_y, pos_z - height);
			glVertex3f(pos_x, pos_y - thickness, pos_z - height);
			glVertex3f(pos_x, pos_y - thickness, pos_z);

			glColor3f(0.9, 0.9, 0.9);
			//top plane
			glVertex3f(pos_x, pos_y, pos_z - height);
			glVertex3f(pos_x + width, pos_y, pos_z - height);
			glVertex3f(pos_x + width, pos_y, pos_z);
			glVertex3f(pos_x, pos_y, pos_z);
			//bottom plane		
			glVertex3f(pos_x, pos_y - thickness, pos_z - height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z - height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z);
			glVertex3f(pos_x, pos_y - thickness, pos_z);
			//-----------------------------------------------------------

			//----------------angled one---------------------------------
			glColor3f(0.8, 0.8, 0.8);
			//back plane
			glVertex3f(pos_x, pos_y, pos_z);
			glVertex3f(pos_x + width, pos_y, pos_z);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z);
			glVertex3f(pos_x, pos_y - thickness, pos_z);
			//front plane
			glVertex3f(pos_x, pos_y - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - thickness - angle, pos_z + height);
			glVertex3f(pos_x, pos_y - thickness - angle, pos_z + height);

			glColor3f(0.8, 0.8, 0.8);
			//right plane
			glVertex3f(pos_x + width, pos_y, pos_z);
			glVertex3f(pos_x + width, pos_y - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - thickness - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z);
			//left plane
			glVertex3f(pos_x, pos_y, pos_z);
			glVertex3f(pos_x, pos_y - angle, pos_z + height);
			glVertex3f(pos_x, pos_y - thickness - angle, pos_z + height);
			glVertex3f(pos_x, pos_y - thickness, pos_z);

			glColor3f(0.9, 0.9, 0.9);
			//top plane
			glVertex3f(pos_x, pos_y - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y, pos_z);
			glVertex3f(pos_x, pos_y, pos_z);
			//bottom plane		
			glVertex3f(pos_x, pos_y - thickness - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - thickness - angle, pos_z + height);
			glVertex3f(pos_x + width, pos_y - thickness, pos_z);
			glVertex3f(pos_x, pos_y - thickness, pos_z);
			//-----------------------------------------------------------
			pos_x = pos_x + width;
		}
		pos_x = -410;
		pos_z += 25;
	}
	glEnd();

	///////////// top design ends /////////////

	///////////// cube items starts /////////////

	glBegin(GL_QUADS);
	////////////////////////////////////////////left wall design///////////////////////////////////////////////////////
	float cb_x = -410, cb_z = -300, cb_y = -5, cb_width = 20, cb_poll_width = 2;

	for (int k = 1; k <= 21; k++)
	{
		cb_z += cb_width / 2;
		if (k % 2 == 0)
		{
			cb_y += cb_width;
		}
		else
		{
			cb_y -= cb_width;
		}
		//================================== item-i-back ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
		//================================================================================================

		//================================== item-i-front ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//================================================================================================

		//================================== item-i-top ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_width, cb_z);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		//================================================================================================

		//================================== item-i-bottom ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
		glVertex3f(cb_x, cb_y, cb_z);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y, cb_z);
		glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
		//================================================================================

		cb_z += cb_width;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////// right wall design /////////////////////////////////////

	cb_x = 405;
	cb_z = -300;
	cb_y = 0;
	cb_width = 20;
	cb_poll_width = 2;


	for (k = 1; k <= 21; k++)
	{
		cb_z += cb_width / 2;
		if (k % 2 == 0)
		{
			cb_y += cb_width;
		}
		else
		{
			cb_y -= cb_width;
		}
		//================================== item-i-back ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
		//================================================================================================

		//================================== item-i-front ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//================================================================================================

		//================================== item-i-top ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_width, cb_z);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_width, cb_z);
		glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
		//================================================================================================

		//================================== item-i-bottom ==========================================
		glColor3f(0.0, 0.0, 1.0);
		//back plane
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
		glVertex3f(cb_x, cb_y, cb_z);
		//front plane
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
		//right plane
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//left plane
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x, cb_y, cb_z);
		glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//top plane
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
		//bottom plane		
		glVertex3f(cb_x, cb_y, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
		glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
		glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
		//================================================================================

		cb_z += cb_width;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////


	/////////////////////////////////////////////////design item1-main item///////////////////////////////////////
	cb_x = -100;
	cb_z = 300;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 4; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			//////////////////////////////////////////horizontal items////////////////////////////////

			//================================== item-horizontal-bottom-back =========================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			//cb_x+=cb_width;
		}
		cb_y += cb_width;
		cb_x = -100;
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	cb_x = -100;
	cb_z = 300;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 4; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////horizontal items///////////////////////////////

			//================================== item-horizontal-bottom-back ==========================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_z -= cb_width;
			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_z = 300;
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


	//----------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------
	/////////////////////////////////////////////////design item2///////////////////////////////////////////////

	cb_x = -400;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items////////////////////////////////////

			//================================== item-horizontal-bottom-back ===============================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			//cb_x+=cb_width;
		}
		cb_y += cb_width;
		cb_x = -400;
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	cb_x = -400;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items/////////////////////////////////

			//================================== item-horizontal-bottom-back =============================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_z += cb_width;
			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_z = -400;
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

	//--------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------------
	/////////////////////////////////////////////////design item3///////////////////////////////////////////////////

	cb_x = 380;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items/////////////////////////////////////////

			//================================== item-horizontal-bottom-back ======================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			//cb_x+=cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_x = 380;
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>vertical>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cb_x = 380;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items/////////////////////////////////////

			//================================== item-horizontal-bottom-back ==================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_z += cb_width;
			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_z = -400;
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//----------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------
	/////////////////////////////////////////////////design item4-small wall-left///////////////////////////////

	cb_x = -50;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items////////////////////////////////////////

			//================================== item-horizontal-bottom-back ===================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			//cb_x+=cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_x = -50;
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>vertical>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cb_x = -50;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items///////////////////////////////////////

			//================================== item-horizontal-bottom-back ====================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_z += cb_width;
			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_z = -400;
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//---------------------------------------------------------------------------------------------------------
	//---------------------------------------------------------------------------------------------------------
	/////////////////////////////////////////////////design item5 small-wall-right/////////////////////////////

	cb_x = 30;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items///////////////////////////////////

			//================================== item-horizontal-bottom-back =================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-bottom-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//==========================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//========================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//============================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			//cb_x+=cb_width;
		}
		cb_y += cb_width;
		cb_x = 30;
	}

	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	cb_x = 30;
	cb_z = -400;
	cb_y = -75;
	cb_width = 20;
	cb_poll_width = 2;

	for (j = 3; j >= 1; j--)
	{
		for (k = 1; k <= j; k++)
		{
			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//=========================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//========================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//============================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			///////////////////////////////////////////////horizontal items////////////////////////////////////

			//================================== item-horizontal-bottom-back ================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//========================================================================================


			//================================== item-horizontal-top-back =============================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width);
			//==========================================================================================


			//================================== item-horizontal-bottom-front ================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================


			//================================== item-horizontal-top-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_width + cb_poll_width, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_width + cb_poll_width);
			//================================================================================================

			//////////////////////////////////////////////////////////////////////////////////////////////////
			cb_x += cb_width;

			//================================== item-i-back ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width);
			//================================================================================================

			//================================== item-i-front ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width + cb_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-top ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_width, cb_z + cb_poll_width + cb_width);
			//================================================================================================

			//================================== item-i-bottom ==========================================
			glColor3f(0.0, 0.0, 1.0);
			//back plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			//front plane
			glColor3f(0.0, 1.0, 1.0);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//right plane
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//left plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//top plane
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y + cb_poll_width, cb_z + cb_poll_width + cb_width);
			//bottom plane		
			glVertex3f(cb_x, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z);
			glVertex3f(cb_x + cb_poll_width, cb_y, cb_z + cb_poll_width + cb_width);
			glVertex3f(cb_x, cb_y, cb_z + cb_poll_width + cb_width);
			//================================================================================

			cb_z += cb_width;
			cb_x -= cb_width;
		}
		cb_y += cb_width;
		cb_z = -400;
	}
	//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	//----------------------------------------------------------------------------------------------------------------------
	glEnd();
	///////////// cube items ends /////////////

	//------- custom code ends   -------

	glutSwapBuffers();
}

void spinDisplay(void)
{
	spin = spin + spin_speed;
	if (spin>360.0)
	{
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}

void spinDisplayReverse(void)
{
	spin = spin - spin_speed;
	if (spin<360.0)
	{
		spin = spin + 360.0;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(spinDisplay);
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(spinDisplayReverse);
		}
		break;

	default:
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	///-------- spin --------
	if (key == 'x')
	{
		setSpin(1.0, 0.0, 0.0);
		glutPostRedisplay();
	}
	else if (key == 'y')
	{
		setSpin(0.0, 1.0, 0.0);
		glutPostRedisplay();
	}
	else if (key == 'z')
	{
		setSpin(0.0, 0.0, 1.0);
		glutPostRedisplay();
	}
	else if (key == 'a')
	{
		setSpin(1.0, 1.0, 1.0);
		glutPostRedisplay();
	}
	///-------- spin --------	

	///-------- zoom --------	
	else if (key == 'i')
	{
		translate_z = translate_z + 5;
		glutPostRedisplay();
	}
	else if (key == 'o')
	{
		translate_z = translate_z - 5;
		glutPostRedisplay();
	}
	///-------- zoom --------

	///-------- go -------
	else if (key == 'g')
	{
		go();
		glutPostRedisplay();
	}
	///-------- go -------

	///-------- set -------
	else if (key == 's')
	{
		set();
		glutPostRedisplay();
	}
	///-------- set -------

	///-------- rotate -------
	else if (key == 'r')
	{
		spin++;
		glutPostRedisplay();
	}
	else if (key == 'R')
	{
		spin--;
		glutPostRedisplay();
	}
	///-------- rotate -------

	///-------- translate -------
	else if (key == 't')
	{
		translate_x += 5;
		glutPostRedisplay();
	}
	else if (key == 'T')
	{
		translate_x -= 5;
		glutPostRedisplay();
	}
	else if (key == 'v')
	{
		translate_y += 5;
		glutPostRedisplay();
	}
	else if (key == 'V')
	{
		translate_y -= 5;
		glutPostRedisplay();
	}
	///-------- translate -------

	///-------- front view -------
	else if (key == 'f')
	{
		spin = 0.0;
		spin_x = 0;
		spin_y = 1;
		spin_z = 0;
		translate_x = 0.0;
		translate_y = 0.0;

		glutPostRedisplay();
	}
	///-------- front view -------
}

/*int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}*/