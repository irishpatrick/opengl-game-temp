#pragma once

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>
#include <vector>
#include <gl/glew.h>

#include "Model.hpp"

typedef struct _Vertex
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texture;
} Vertex;

class Mesh
{
public:
    Mesh()
    {

    }

    ~Mesh()
    {

    }

    void init();
    void draw();

private:
    std::vector<Vertex> vertices;
    GLuint vao, vbo, ebo;
};
