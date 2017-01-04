#include "stdafx.h"
#include "Spring.h"


Spring::Spring()
{
}


Spring::~Spring()
{
}

void Spring::draw(GLfloat start_y) {	
	GLfloat end_y= 50.0f;
	GLfloat start_cylinder_length = 5.0f;
	GLfloat cylinder_radius = 1.0f;
	GLfloat sphere_radius = 1.0f;
	GLfloat end_cylinder_length = 5+abs(start_y)/100;
	GLfloat end_coil_y = end_y-end_cylinder_length;
	GLfloat start_coil_y = start_y + start_cylinder_length;
	GLfloat step_coil_y = (end_coil_y- start_coil_y)/30;
	GLfloat SPRING_DIAMETER_X=2.0f;
	GLfloat SPRING_DIAMETER_Z = 0.2f;
	GLfloat spring_x, spring_y, spring_z;
	GLUquadricObj *quadObj = gluNewQuadric();
	glDisable(GL_TEXTURE_2D);
	
	glPushMatrix();
	glTranslated(0.0, end_y, -2.0);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);	
	glutSolidSphere(sphere_radius, 20, 20);
	glPopMatrix();

	glPushMatrix();	
	glTranslated(0.0, end_y - sphere_radius, -5.0);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glutSolidCylinder(cylinder_radius, end_cylinder_length, 20, 20);
	glPopMatrix();

	glPushMatrix();	
	glTranslated(0.0, start_y, -2.0);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glutSolidSphere(sphere_radius, 20, 20);	
	glPopMatrix();

	glPushMatrix();	
	glTranslated(0.0, start_y + sphere_radius, -5.0);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glutSolidCylinder(cylinder_radius, start_cylinder_length, 20, 20);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslated(-2.0, 0.0, -5.0);
	glLineWidth(1.0f);
	for (GLfloat coil_y = start_coil_y; coil_y <= end_coil_y; coil_y += step_coil_y) {
		
		glBegin(GL_LINE_STRIP);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		for (GLfloat u = 2 * PI, t = 8 * PI; u > 0.0f, t > 0.0f; u -= 0.1f, t -= 0.1f) {
			spring_x = cos(t)*(3 + cos(u))*SPRING_DIAMETER_X;
			spring_y = sin(t)*(3 + cos(u))+coil_y;
			spring_z = ((0.6*t / 360) + sin(u))*SPRING_DIAMETER_Z;
			glVertex3f(spring_x, spring_y, spring_z);
		}
		glEnd();
	}	
	glPopMatrix();
	

}
