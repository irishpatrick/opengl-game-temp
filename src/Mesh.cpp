#include "Mesh.hpp"

void Mesh::init()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(
        GL_ARRAY_BUFFER,
        vertices.size() * sizeof(Vertex),
        &vertices[0],
        GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0, 3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (void*)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(
        2, 2, 
        GL_FLOAT,
        GL_FALSE,
        sizeof(Vertex),
        (void*)offsetof(Vertex, texture));

    glBindVertexArray(0);
}
