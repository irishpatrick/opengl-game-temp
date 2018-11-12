#pragma once

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader();
	~Shader();

	void loadShader(const std::string&, GLenum);
	void linkProgram();
	void use();
	void detach();

	void setMatrix4(const std::string&, const glm::mat4&);

	GLuint getProgramId()
	{
		return m_pid;
	}

private:
	GLuint m_vsid;
	GLuint m_gsid;
	GLuint m_fsid;
	GLuint m_pid;
	std::string readFile(const std::string&);
};
