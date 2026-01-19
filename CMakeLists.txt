cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME OpenFlightSimulator)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

include_directories(include/)
include_directories(external/)
include_directories(external/imgui/)
include_directories(external/glad/include/)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/App.cpp
    src/Window.cpp

    # UI
    src/UI/ui.cpp

    # Renderer
    src/Renderer/Renderer.cpp
    src/Renderer/ShaderLoader.cpp
    src/Renderer/Mesh/Mesh.cpp
    src/Renderer/Camera.cpp
    src/Renderer/Texture/Texture.cpp
    src/Renderer/Texture/TextureLoader.cpp

    # Physics engine
    src/VectorPhysics/Atmosphere.cpp

    # Dependencies
    external/glad/src/glad.c
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_demo.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
