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

    useTexture = false;
}

void Crunch::Mesh::uploadToGpu()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);      // position
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); // UV
    glEnableVertexAttribArray(1);
}

void Crunch::Mesh::setColor(glm::vec4 c)
{
    color = c;
}

void Crunch::Mesh::setTexture(unsigned int texId)
{
    textureId = texId;
    useTexture = true;
}
