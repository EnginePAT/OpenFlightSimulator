#include <Renderer/Mesh/Mesh.hpp>
#include <glm/gtc/type_ptr.hpp>


Crunch::Mesh::Mesh()
{
    // vertices.assign(verts, verts + vertCount);
    // indices.assign(idx, idx + indexCount);

    // this->indexCount = indexCount;
    // this->vertexCount = vertCount;

    model = glm::mat4(1.0f);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
}

void Crunch::Mesh::uploadToGpu()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Crunch::Mesh::setColor(glm::vec4 c)
{
    color = c;
}
