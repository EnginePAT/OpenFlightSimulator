#ifndef MESH_HPP
#define MESH_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>


class Mesh
{

public:
    unsigned int VAO, VBO, EBO;
    unsigned int vertexCount;
    unsigned int indexCount;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    Mesh(float verts[], unsigned int vertCount, unsigned int indices[], unsigned int indexCount);

};


#endif      // MESH_HPP
