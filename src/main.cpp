#include <Window.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Mesh/Mesh.hpp>
#include <iostream>

int main() {
    Window window(800, 600, "OpenFlightSimulator | Version 2026.0.1 Alpha");
    Renderer renderer;
    Mesh mesh(renderer.vertices, 9, renderer.indices, 6);

    while (!glfwWindowShouldClose(window.window))
    {
        window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        renderer.draw(mesh, glm::vec4(1));

        window.PollEvents();
    }

    window.Terminate();
    return 0;
}
