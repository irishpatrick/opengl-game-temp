#pragma once

#include <GL/glew.h>
#include "Model.hpp"

class TestTriangle : public Model
{
public:
	TestTriangle();
	~TestTriangle();

	void init();

private:
	const GLfloat vertex_array[9] = 
	{
		0.0f, 0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f
	};
};