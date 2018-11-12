#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <vector>

Shader::Shader()
{

}

Shader::~Shader()
{

}

void printInfoLog(const std::vector<GLchar>& log)
{
	for (auto i = log.begin(); i != log.end(); i++)
	{
		std::cout << *i << ' ';
	}
	std::cout << std::endl;
}

void Shader::loadShader(const std::string& fn, GLenum type)
{
	std::string content = readFile(fn);
	if (content.size() == 0)
	{
		std::cout << "error reading " << fn << std::endl;
		return;
	}
	char* data = const_cast<char*>(content.c_str());
	GLuint current_id = glCreateShader(type);

	switch (type)
	{
		case GL_VERTEX_SHADER:
			m_vsid = current_id;
			break;
		case GL_FRAGMENT_SHADER:
			m_fsid = current_id;
			break;
	}

	size_t t = content.length();

	glShaderSource(current_id, 1, &data, (const GLint*) &t);
	glCompileShader(current_id);

	GLint isCompiled = 0;
	glGetShaderiv(current_id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		std::cout << "error: compile of " << fn << " failed!" << std::endl;

		GLint maxLength = 0;
		glGetShaderiv(current_id, GL_INFO_LOG_LENGTH, &maxLength);
		std::cout << "get info log length: " << maxLength << std::endl;

		std::vector<GLchar> infoLog(maxLength);
		std::cout << "make vector" << std::endl;
		glGetShaderInfoLog(current_id, maxLength-1, &maxLength, &infoLog[0]);
		std::cout << "copy log into vector" << std::endl;

		//std::cout << infoLog.size() << std::endl;
		//printInfoLog(infoLog);
		std::cout << "INFO LOG: " << &infoLog[0] << std::endl;

		return;
	}
	else
	{
		std::cout << "compilation of " << fn << " succeded" << std::endl;
	}
}

void Shader::linkProgram()
{
	m_pid = glCreateProgram();
	if (m_vsid != 0)
	{
		glAttachShader(m_pid, m_vsid);
	}
	else
	{
		std::cout << "vertex shader error" << std::endl;
	}
	if (m_fsid != 0)
	{
		glAttachShader(m_pid, m_fsid);
	}
	else
	{
		std::cout << "fragment shader error" << std::endl;
	}

	glLinkProgram(m_pid);

	glDeleteShader(m_vsid);
	glDeleteShader(m_fsid);

	//glBindFragDataLocation(m_pid, 0, "color");
}

void Shader::use()
{
	glUseProgram(m_pid);
}

void Shader::detach()
{
	glUseProgram(0);
}

std::string Shader::readFile(const std::string& fn)
{
	std::ifstream in(fn);
	if (in.fail())
	{
		std::cout << fn << " does not exist" << std::endl;
		return "";
	}

	std::stringstream buffer;
	buffer << in.rdbuf();
	std::string content = buffer.str();
	return content;
}

void Shader::setMatrix4(const std::string& name, const glm::mat4& matrix)
{
	GLint id = glGetUniformLocation(m_pid, name.c_str());
	if (id == -1)
	{
		//std::cout << "bad uniform name" << std::endl;
		return;
	}
	glUniformMatrix4fv(id, 1, GL_FALSE, &matrix[0][0]);
}
