#ifndef UI_HPP
#define UI_HPP


#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>


class UI
{
public:
    UI(GLFWwindow* window);
    ~UI();

    void beginFrame();
    void render();
    void endFrame();


private:
    GLFWwindow* window;
};


#endif      // UI_HPP
