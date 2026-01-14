#include <Window.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Mesh/Mesh.hpp>
#include <Renderer/Camera.hpp>
#include <iostream>

int main() {
    Window window(800, 600, "OpenFlightSimulator | Version 2026.0.1 Alpha");
    Renderer renderer;
    Mesh mesh(renderer.vertices, 9, renderer.indices, 6);
    Camera camera(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

    glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

    while (!glfwWindowShouldClose(window.window))
    {
        window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        renderer.draw(mesh, color);

        unsigned int modelLoc = glGetUniformLocation(renderer.shaderProgram, "model");
        unsigned int viewLoc = glGetUniformLocation(renderer.shaderProgram, "view");
        unsigned int projectionLoc = glGetUniformLocation(renderer.shaderProgram, "projection");

        glm::mat4 model = glm::mat4(1.0f);

        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.view));
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(camera.projection));

        window.PollEvents();
    }

    window.Terminate();
    return 0;
}
