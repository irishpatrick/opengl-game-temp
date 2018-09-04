#include "Model.hpp"

Model::Model()
{

}

Model::~Model()
{

}

void Model::init()
{
	glGenBuffers(1, m_vbo);
	glGenVertexArrays(1, m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo[0]);
	
	uint32_t size = (m_verts.size() * sizeof(GLfloat));
	glBufferData(GL_ARRAY_BUFFER, size, &m_verts[0], GL_STATIC_DRAW);

	glBindVertexArray(m_vao[0]);

	glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(positionAttributeIndex);
}

void Model::draw()
{

}