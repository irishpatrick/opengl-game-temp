#include "Shader.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>

Shader::Shader()
{

}

Shader::~Shader()
{

}

void Shader::loadShader(const std::string& fn, GLenum type)
{
	std::string content = readFile(fn);
	char* data = const_cast<char*>(content.c_str());
	m_vsid = glCreateShader(type);
	glShaderSource(m_vsid, 1, &data, &(int32_t)content.length());
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