#include <Renderer/Renderer.hpp>
#include <Renderer/Shaders.h>
#include <glm/gtc/type_ptr.hpp>

Crunch::Renderer::Renderer()
{
    unsigned int vertexShader = ShaderLoader::compileShader(GL_VERTEX_SHADER, Shaders::vertexShaderSource);
    unsigned int fragmentShader = ShaderLoader::compileShader(GL_FRAGMENT_SHADER, Shaders::fragmentShaderSource);
    shaderProgram = ShaderLoader::compileShaderProgram(vertexShader, fragmentShader);
}

void Crunch::Renderer::draw(Camera& camera, Mesh &mesh)
{
    glUseProgram(shaderProgram);

    unsigned int colorLoc = glGetUniformLocation(shaderProgram, "meshColor");
    unsigned int modelLoc = glGetUniformLocation(shaderProgram, "model");
    unsigned int viewLoc = glGetUniformLocation(shaderProgram, "view");
    unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(mesh.model));
    glUniform4f(colorLoc, mesh.color.x, mesh.color.y, mesh.color.z, mesh.color.w);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.projection));

    glBindVertexArray(mesh.VAO);
    glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
