#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

class Camera
{
public:
    Camera()
    {
        matrix = glm::mat4(1.0f);
        position = glm::vec3(0.0f);
    }

    ~Camera()
    {

    }

    glm::mat4 getMatrix();

    void update();

    glm::vec3 position;
    glm::vec3 rotation;

private:
    glm::mat4 matrix;
    glm::mat4 translationMatrix;
    glm::mat4 projectionMatrix;
    glm::mat4 rotationMatrix;
};
