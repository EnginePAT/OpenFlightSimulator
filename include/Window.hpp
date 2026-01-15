#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


namespace Crunch
{

class Window
{
public:
    GLFWwindow* window;

    Window(int width, int height, const char* title);

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    void Clear(glm::vec4 color);
    void PollEvents();
    void Terminate();
};

};


#endif      // WINDOW_HPP
