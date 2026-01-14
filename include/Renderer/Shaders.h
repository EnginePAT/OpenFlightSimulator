#ifndef SHADERS_H
#define SHADERS_H


class Shaders
{
public:
    static inline const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        uniform mat4 view;
        uniform mat4 model;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * model * view * vec4(aPos, 1.0);
        }
    )";

    static inline const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        uniform vec4 meshColor;

        void main()
        {
            FragColor = meshColor;
        }
    )";
};


#endif      // SHADERS_H
