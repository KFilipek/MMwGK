#include "stdafx.h"
#include "Spring.h"


Spring::Spring()
{
}


Spring::~Spring()
{
}

void Spring::draw(GLfloat end_Y) {	
	GLfloat start_y= 50.0f;
	GLfloat step_y = 0.0f;
	GLfloat u[1000], t[1000], spring_X[1000], spring_Y[1000], spring_Z[1000];
	glEnable(GL_DEPTH);
	glDepthFunc(GL_LEQUAL);
	glDisable(GL_TEXTURE_2D);
	//glTranslated(0.0, 70.0+start_Y, -10.0);
	for (int i = 0; i < 1000; i++) {
		t[i] = (i) * 8 * PI / (999*180);
		u[i] = (i) * 2 * PI / (999*180);
		spring_X[i] = cos(t[i])*(3 + cos(u[i]));
		spring_Y[i] = sin(t[i])*(3 + cos(u[i]));
		spring_Z[i] = 0.6*t[i] + sin(u[i]);
	}
	glTranslatef(0.0f, 0.0f, -5.0f);
	for (int j = 0; j < 5; j++) {	
		
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		
		glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
		for (int i = 0; i < 200; i++) {
			glVertex3f(spring_X[j*200+i], spring_Y[j*200+i]*100+start_y-step_y, spring_Z[j*200+i]);
		}
		glEnd();
		step_y = (j+1)*(start_y - abs(end_Y)) / 5;
	}
	
	
}
