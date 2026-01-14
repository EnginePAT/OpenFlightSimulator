#ifndef CAMERA_HPP
#define CAMERA_HPP


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera
{
public:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;

    float fov;
    float aspect;
    float nearPlane;
    float farPlane;

    glm::mat4 projection;
    glm::mat4 view;

    Camera(float fov, float aspect, float nearPlane, float farPlane);

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;
};


#endif      // CAMERA_HPP
