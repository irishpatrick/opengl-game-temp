#pragma once

#include <GL/glew.h>
#include <cstdint>
#include <vector>

class Model
{
public:
	Model();
	virtual ~Model();

	virtual void init();
	virtual void draw();

private:
	const uint32_t positionAttributeIndex = 0;
	static const GLuint m_vboNum = 1;
	GLuint m_vbo[m_vboNum];
	GLuint m_vao[1];
	std::vector<GLfloat> m_verts;
};