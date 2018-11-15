#pragma once

#include <GL/glew.h>
#include <cstdint>
#include <vector>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

class Model
{
public:
	Model();
	virtual ~Model();

	virtual void init();
	virtual void update();
	virtual void draw();
	virtual glm::mat4 getMatrix();

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

protected:
	const uint32_t positionAttributeIndex = 0;
	static const GLuint m_vboNum = 1;
	GLuint m_vbo[m_vboNum];
	GLuint m_vao[1];
	std::vector<GLfloat> m_verts;

	glm::mat4 matrix;

private:
	bool ready;
	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;
};
