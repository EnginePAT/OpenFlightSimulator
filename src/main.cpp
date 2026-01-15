#include <Window.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Mesh/Mesh.hpp>
#include <Renderer/Camera.hpp>
#include <Shapes.h>
#include <iostream>

int main() {
    Window window(800, 600, "OpenFlightSimulator | Version 2026.0.1 Alpha");
    Renderer renderer;
    Mesh mesh = Shape::Quad(glm::vec3(0.5f), 1.0f, 1.0f, glm::vec4(1.0f));
    Mesh mesh2 = Shape::Quad(glm::vec3(-0.5f), 1.0f, 1.0f, glm::vec4(0.25f));
    Camera camera(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

    while (!glfwWindowShouldClose(window.window))
    {
        window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        renderer.draw(camera, mesh);
        renderer.draw(camera, mesh2);

        window.PollEvents();
    }

    window.Terminate();
    return 0;
}
