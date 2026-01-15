// Global includes
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

// Local includes
#include <Window.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Mesh/Mesh.hpp>
#include <Renderer/Camera.hpp>
#include <Shapes.h>


int main() {

    const int screenWidth = 800;
    const int screenHeight = 600;
    
    // Create window, renderer and camera
    Crunch::Window window(screenWidth, screenHeight, "OpenFlightSimulator | Version 2026.0.1 Alpha");
    Crunch::Renderer renderer;
    Crunch::Camera camera(45.0f, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
    camera.position = glm::vec3(0, 0, 20.0f);


    // Create a ground plane object
    Crunch::Mesh ground = Crunch::Shape::Quad(glm::vec3(0), 10.f, 10.f, glm::vec4(0.65f, 0.33f, 0.0f, 1.0f));
    glm::mat4 groundRotation = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0, 0));
    ground.model = groundRotation;
    ground.uploadToGpu();


    while (!glfwWindowShouldClose(window.window))
    {
        // Clear the window to a blue->green colour
        window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        // Draw the mesh objects we created
        renderer.draw(camera, ground);

        // PollEvents (Allow window to close) & SwapBuffers
        window.PollEvents();
    }

    // Cleanup and return
    window.Terminate();
    return 0;
}
