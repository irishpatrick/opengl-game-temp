#include "Camera.hpp"

glm::mat4 Camera::getMatrix()
{
    return matrix;
}

void Camera::update()
{
    translationMatrix = glm::translate(glm::mat4(1.0f), position);
	matrix = translationMatrix;
}
