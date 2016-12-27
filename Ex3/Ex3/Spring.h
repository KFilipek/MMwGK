#pragma once

#include "stdafx.h"
#include "Sphere.h"

class Spring
{
protected:
	const GLfloat STEP = 8 * PI / 1800;
	const GLfloat spring_size = 10.0f;
	GLfloat u, t;
public:
	Spring();
	~Spring();
	
	void draw(GLfloat start_Y);
};

