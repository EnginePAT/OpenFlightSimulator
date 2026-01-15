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

    // 1. Upload Vertex Data (x, y, z)
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // 2. Upload Index Data (Crucial for EBO to work)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // 4. DISABLE UV Attribute (Location 1) so it doesn't mess with memory
    glDisableVertexAttribArray(1);
    // 4. UV Attribute (Location 1)
    // Stride is 5. Offset is 3 (skipping x, y, z).
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(5 * sizeof(float)));     // NOTE: THIS IS CAUSING PROBLEMS. REWRITE TEXTURE DRIVER!
    glEnableVertexAttribArray(1);

    // 3. Set Position Attribute ONLY
    // Stride is 3 * float because we removed UVs
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 5. UNBIND VAO FIRST to lock in the EBO binding
    glBindVertexArray(0);

    // 6. Safe to unbind buffers now
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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

void Crunch::Mesh::move(glm::vec3 newPos)
{
    model = glm::translate(model, newPos);
}

void Crunch::Mesh::setPosition(glm::vec3 newPos)
{
    model = glm::translate(glm::mat4(1.0f), newPos);
}
