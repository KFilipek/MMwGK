#include "stdafx.h"
#include "Spring.h"


Spring::Spring()
{
}


Spring::~Spring()
{
}

void Spring::draw() {
	glEnable(GL_DEPTH);
	glDisable(GL_TEXTURE_2D);
	GLfloat u[1001], t[1001], spring_X[1001], spring_Y[1001], spring_Z[1001];
	glTranslated(0.0, 0.0, -2.0);
	glRotatef(360.0f, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i < 1001; i++) {
		t[i] = 0.0f; u[i] = 0.0f;
		spring_X[i] = 0.0f; spring_Y[i] = 0.0f; spring_Z[i] = 0.0f;
	}
	for (int j = 0; j < 10; j++) {
		GLfloat spring_x_step = j*1.0f, spring_y_step = j*5.0f, spring_z_step = j*1.0f;
		for (int i = 0; i < 100; i++) {
			spring_X[i] = (cos(t[i]))*(3 + (cos(u[i])));
			spring_Y[i] = (sin(t[i]))*(3 + (cos(u[i])));
			spring_Z[i] = (0.6*t[i]) + (sin(u[i]));
			
			t[i+1] =t[i]+ STEP;
			u[i+1] =u[i]+ STEP;
			if (u[i] >= (2 * PI/180))
				u[i] -= 2 * PI/180;
		}
	}
	spring_X[1000] = (cos(t[1000]))*(3 + (cos(u[1000])));
	spring_Y[1000] = (sin(t[1000]))*(3 + (cos(u[1000])));
	spring_Z[1000] = (0.6*t[1000]) + (sin(u[1000]));
	
	glBegin(GL_LINE_STRIP);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	for (int i = 0; i < 1001; i++) {
		glVertex3f(spring_X[i], spring_Y[i]+10.0f, spring_Z[i]);
	}	
	glEnd();
	
}
