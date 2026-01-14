#ifndef WINDOW_HPP
#define WINDOW_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


class Window
{
public:
    GLFWwindow* window;

    Window(int width, int height, const char* title);

    void Clear(glm::vec4 color);
    void PollEvents();
    void Terminate();
};


#endif      // WINDOW_HPP
