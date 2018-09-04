#pragma once

#include <GL/glew.h>
#include "Model.hpp"

class TestTriangle : public Model
{
public:
	TestTriangle();
	~TestTriangle();

private:
	const GLfloat vertex_array[3][3] = 
	{
		{0.0f, 0.5f, 0.5f},
		{0.5f, -0.5f, 0.5f},
		{-0.5f, -0.5f, 0.5f}
	};
};