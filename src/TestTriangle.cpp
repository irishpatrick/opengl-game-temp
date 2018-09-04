#include "TestTriangle.hpp"
#include <algorithm>

TestTriangle::TestTriangle() : Model()
{

}

TestTriangle::~TestTriangle()
{

}

void TestTriangle::init()
{
	// set vertices
	m_verts = std::vector<GLfloat>(9);
	std::copy(vertex_array, vertex_array + 9, m_verts.begin());

	// init model
	Model::init();
}