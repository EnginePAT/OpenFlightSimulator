#include <Window.hpp>
#include <iostream>

int main() {
    Window window(800, 600, "OpenFlightSimulator | Version 2026.0.1 Alpha");

    while (!glfwWindowShouldClose(window.window))
    {
        window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));
        window.PollEvents();
    }

    window.Terminate();
    return 0;
}
