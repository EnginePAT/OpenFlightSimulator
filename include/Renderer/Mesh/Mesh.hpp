#ifndef MESH_HPP
#define MESH_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector>


namespace Crunch
{

class Mesh
{

public:
    unsigned int VAO, VBO, EBO;
    unsigned int vertexCount;
    unsigned int indexCount;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;

    unsigned int textureId = 0;
    bool useTexture = false;

    glm::mat4 model;
    glm::vec4 color;

    // Mesh contructor properties
    // float verts[], unsigned int vertCount, unsigned int indices[], unsigned int indexCount

    Mesh();
    void uploadToGpu();
    void setColor(glm::vec4 c);
    void setTexture(unsigned int texId);
    void move(glm::vec3 newPos);
    void setPosition(glm::vec3 newPos);

};

};


#endif      // MESH_HPP
