#include <Renderer/Renderer.hpp>
#include <Renderer/Shaders.h>

Renderer::Renderer()
{
    unsigned int vertexShader = ShaderLoader::compileShader(GL_VERTEX_SHADER, Shaders::vertexShaderSource);
    unsigned int fragmentShader = ShaderLoader::compileShader(GL_FRAGMENT_SHADER, Shaders::fragmentShaderSource);
    shaderProgram = ShaderLoader::compileShaderProgram(vertexShader, fragmentShader);
}

void Renderer::draw(Mesh &mesh, glm::vec4& color)
{
    glUseProgram(shaderProgram);

    glUniform4f(glGetUniformLocation(shaderProgram, "meshColor"), color.x, color.y, color.z, color.w);

    glBindVertexArray(mesh.VAO);
    glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
