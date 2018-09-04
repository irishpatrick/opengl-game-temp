#include "Model.hpp"
#include <iostream>

Model::Model()
{
	ready = false;
}

Model::~Model()
{

}

void Model::init()
{
	if (m_verts.size() == 0)
	{
		std::cout << "cannot init with 0 vertices" << std::endl;
		return;
	}

	glGenBuffers(1, m_vbo);
	glGenVertexArrays(1, m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[0]);
	
	uint32_t size = (m_verts.size() * sizeof(GLfloat));
	glBufferData(GL_ARRAY_BUFFER, size, &m_verts[0], GL_STATIC_DRAW);

	glBindVertexArray(m_vao[0]);
	glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	ready = true;
}

void Model::draw()
{
	if (!ready)
	{
		return;
	}

	glBindVertexArray(m_vao[0]);
	glEnableVertexAttribArray(positionAttributeIndex);

	glDrawArrays(GL_TRIANGLES, 0, m_verts.size() / 3);

	glDisableVertexAttribArray(positionAttributeIndex);
	glBindVertexArray(0);
}