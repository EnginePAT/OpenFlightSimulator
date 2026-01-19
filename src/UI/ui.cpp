#include <UI/ui.hpp>


UI::UI(GLFWwindow* window)
{
    // Create ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    // Set style
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

UI::~UI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UI::beginFrame()
{
    ImGui_ImplGlfw_NewFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();
}

void UI::render()
{
    // == UI Rendering Here ==
    ImGui::Begin("Debug Panel");

    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UI::endFrame()
{
    // OPTIONAL: Useful for adding post render tasks to the UI
}
