cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME OpenFlightSimulator)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

include_directories(include/)
include_directories(external/)
include_directories(external/glad/include/)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Window.cpp

    # Renderer
    src/Renderer/Renderer.cpp
    src/Renderer/ShaderLoader.cpp
    src/Renderer/Mesh/Mesh.cpp

    external/glad/src/glad.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
