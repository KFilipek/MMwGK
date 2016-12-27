#include "stdafx.h"
#include "Board.h"


Board::Board()
{
}


Board::~Board()
{
}

void Board::draw() {
	glPushMatrix();
	glEnable(GL_DEPTH);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_TEXTURE_2D);
	
	glTranslated(0.0f,	145.0f, -6.0f);
	glRotated(270.0, 1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glColor4f(0.6f, 0.2f, 0.0f, 1.0f);
	glVertex3f(-30.0f, 0.0f, 0.5f);
	glVertex3f(30.0f, 0.0f, 0.5f);
	glVertex3f(30.0f, 0.0f, -0.5f);
	glVertex3f(-30.0f, 0.0f, -0.5f);

	glVertex3f(-30.0f, 0.2f, 0.5f);
	glVertex3f(30.0f, 0.2f, 0.5f);
	glVertex3f(30.0f, 0.2f, -0.5f);
	glVertex3f(30.0f, 0.2f, -0.5f);

	glVertex3f(-30.0f, 0.0f, -0.5f);
	glVertex3f(30.0f, 0.0f, -0.5f);
	glVertex3f(30.0f, 0.2f, -0.5f);
	glVertex3f(-30.0f, 0.2f, -0.5f);

	glVertex3f(-30.0f, 0.0f, 0.5f);
	glVertex3f(30.0f, 0.0f, 0.5f);
	glVertex3f(30.0f, 0.2f, 0.5f);
	glVertex3f(-30.0f, 0.2f, 0.5f);

	glVertex3f(-30.0f, 0.0f, -0.5f);
	glVertex3f(-30.0f, 0.0f, 0.5f);
	glVertex3f(-30.0f, 0.2f, 0.5f);
	glVertex3f(-30.0f, 0.2f, -0.5f);

	glVertex3f(30.0f, 0.0f,-0.5f);
	glVertex3f(30.0f, 0.0f, 0.5f);
	glVertex3f(30.0f, 0.2f, 0.5f);
	glVertex3f(30.0f, 0.2f, -0.5f);

	glEnd();
	glPopMatrix();


}
