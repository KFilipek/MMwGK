#pragma once

#include "stdafx.h"
#include "Sphere.h"

class Spring
{
protected:
	GLfloat u, t;
public:
	Spring();
	~Spring();
	
	void draw(GLfloat start_Y);
};

