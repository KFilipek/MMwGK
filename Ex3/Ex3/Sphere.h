#pragma once
#include "stdafx.h"
class Sphere
{
protected:
	
	const GLuint slices = 50, stacks = 50;	
public: 
	const GLdouble radius = 12.0f;
	GLuint texture_id;
public:
	Sphere();
	~Sphere();
	void draw();
	void set_texture(GLuint texture_id);
	
};

