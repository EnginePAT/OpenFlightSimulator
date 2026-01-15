// Global includes
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

// Local includes
#include <Window.hpp>
#include <Renderer/Renderer.hpp>
#include <Renderer/Mesh/Mesh.hpp>
#include <Renderer/Camera.hpp>
#include <Shapes.h>
#include <Renderer/Texture/Texture.hpp>

#include <VectorPhysics/Atmosphere.hpp>


int main() {

    const int screenWidth = 1280;
    const int screenHeight = 800;
    
    // Create window, renderer and camera
    Crunch::Window window(screenWidth, screenHeight, "OpenFlightSimulator | Version 2026.0.1 Alpha");
    Crunch::Renderer renderer;
    Crunch::Camera camera(45.0f, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
    camera.position = glm::vec3(0, 0, 20.0f);


    Crunch::Texture groundTexture;
    groundTexture.loadFromFile("../assets/runway.jpeg");
    Crunch::Texture cubeTexture;
    cubeTexture.loadFromFile("../assets/defaultCube.png");


    // Create a ground plane object
    Crunch::Mesh ground = Crunch::Shape::Quad(glm::vec3(0), 10.f, 10.f, glm::vec4(0.65f, 0.33f, 0.0f, 1.0f));
    glm::mat4 groundRotation = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0, 0));
    ground.model = groundRotation;
    ground.uploadToGpu();

    // Create a test cube
    Crunch::Mesh cube = Crunch::Shape::Cube(glm::vec3(0, 1.0f, 0), 1.0f, 1.0f, 1.0f, glm::vec4(1.0f));
    ground.setTexture(groundTexture.id);
    cube.setTexture(cubeTexture.id);


    double rho = VectorPhysics::Atmosphere::getAirDensity(100);         // Whats the air density at 100m above sea level?
    std::cout << rho << std::endl;


    while (!glfwWindowShouldClose(window.window))
    {
        // Clear the window to a blue->green colour
        window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        // Draw the mesh objects we created
        renderer.draw(camera, ground);
        renderer.draw(camera, cube);

        // PollEvents (Allow window to close) & SwapBuffers
        window.PollEvents();
    }

    // Cleanup and return
    window.Terminate();
    return 0;
}
