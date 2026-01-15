#ifndef RENDERER_HPP
#define RENDERER_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "ShaderLoader.hpp"
#include "Mesh/Mesh.hpp"
#include "Camera.hpp"


class Renderer : public ShaderLoader
{
public:
    static inline float vertices[] = {
        0.5f,  0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    static inline unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    unsigned int VBO, VAO, EBO;
    unsigned int shaderProgram;

    Renderer();

    void draw(Camera& camera, Mesh& mesh);
};


#endif      // RENDERER_HPP
