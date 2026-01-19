#ifndef APP_H
#define APP_H


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
#include <UI/ui.hpp>

#include <VectorPhysics/Atmosphere.hpp>


class App
{
private:
    static const int screenWidth = 1280;
    static const int screenHeight = 800;

    double lastTime = glfwGetTime();
    double acceleration = -9.81;                                        // 9.81 m/s^2 (Gravity)
    double velocity = 0;
    double currentPos = 5.0;
    double dt;

public:
    // Rendering Objects
    Crunch::Window window;
    Crunch::Renderer renderer;
    Crunch::Camera camera;
    UI gui;

    // Mesh Objects
    Crunch::Mesh cube = Crunch::Shape::Cube(glm::vec3(0, 1.0f, 0), 1.0f, 1.0f, 1.0f, glm::vec4(1.0f));
    Crunch::Mesh ground = Crunch::Shape::Quad(glm::vec3(0), 10.f, 10.f, glm::vec4(0.65f, 0.33f, 0.0f, 1.0f));

    // Textures
    Crunch::Texture groundTexture;
    Crunch::Texture cubeTexture;

    App();

    void update();
    void render();
};


#endif      // APP_H
