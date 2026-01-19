#include <Window.hpp>
#include <iostream>

Crunch::Window::Window(int width, int height, const char* title)
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
    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Crunch::Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Crunch::Window::Clear(glm::vec4 color)
{
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool Crunch::Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Crunch::Window::PollEvents()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Crunch::Window::Terminate()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
