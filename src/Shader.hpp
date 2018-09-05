#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
public:
	Shader();
	~Shader();

	void loadShader(const std::string&, GLenum);

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

