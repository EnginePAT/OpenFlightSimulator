#include <Window.hpp>
#include <iostream>

Window::Window(int width, int height, const char* title)
{
    if (!glfwInit())
    {
        std::cerr << "[ERROR]: Failed to initialize OpenGL!" << std::endl;
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        std::cerr << "[ERROR]: Failed to create OpenGL window!" << std::endl;
        return;
    }
    glfwMakeContextCurrent(window);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[ERROR]: Failed to initialize GLAD!" << std::endl;
        return;
    }
    glEnable(GL_DEPTH_TEST);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Window::Clear(glm::vec4 color)
{
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::PollEvents()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::Terminate()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
