#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

void Sphere::draw(GLfloat start_y) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDepthFunc(GL_LESS);
	glPushMatrix();	
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, start_y, -5.0f);
	glutSolidSphere(radius, slices, stacks);
	glPopMatrix();	
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	
	
}

void Sphere::set_texture(GLuint texture_id) {
	this->texture_id = texture_id;
}


