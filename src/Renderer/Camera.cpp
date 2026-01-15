#include <Renderer/Camera.hpp>


Crunch::Camera::Camera(float fov, float aspect, float nearPlane, float farPlane)
{
    position = glm::vec3(3, 5, 15.0f);
    target = glm::vec3(0);
    up = glm::vec3(0, 1.0f, 0);

    projection = glm::perspective(glm::radians(fov), aspect, nearPlane, farPlane);
    view = glm::lookAt(position, target, up);
}
