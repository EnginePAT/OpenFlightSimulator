#include "App.h"

App::App() : window(screenWidth, screenHeight, "OpenFlightSimulator | Version 2026.0.1 Alpha"), 
    camera(45.0f, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f), gui(window.window)
{
    // Create window, renderer and camera
    camera.position = glm::vec3(0, 0, 20.0f);


    // Load the texture files
    groundTexture.loadFromFile("../assets/runway.jpeg");
    cubeTexture.loadFromFile("../assets/defaultCube.png");


    // Create a ground plane object
    glm::mat4 groundRotation = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0, 0));
    ground.model = groundRotation;
    ground.uploadToGpu();

    // Create a test cube
    ground.setTexture(groundTexture.id);
    cube.setTexture(cubeTexture.id);
    cube.setPosition(glm::vec3(0, 5.0f, 0));


    double rho = VectorPhysics::Atmosphere::getAirDensity(100);         // Whats the air density at 100m above sea level?
    std::cout << "Air density: " << rho << std::endl;
    double timeElased;                                                  // How long did it take?
}



void App::update()
{
    /*
        Update
    */
    double currentTime = glfwGetTime();
    dt = currentTime - lastTime;
    lastTime = currentTime;


    // Calculate the kinematic equation using Euler / Midpoint Integration
    velocity += acceleration * dt;
    cube.setPosition(glm::vec3(0, currentPos += velocity * dt, 0));

      // Check if the cube hit the ground
    if (currentPos <= 0.5)
    {
        velocity *= -0.5;                                            // Add a little bounce on impact
        currentPos = 0.5;
    }
}

void App::render()
{
    /*
        Draw
    */
    window.Clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));                // Clear the window to a blue->green colour

    // Draw the mesh objects we created
    renderer.draw(camera, ground);
    renderer.draw(camera, cube);


    // Render the UI
    gui.beginFrame();
    gui.render();



    /*
        PollEvents & Swap buffers
    */
    window.PollEvents();
}
