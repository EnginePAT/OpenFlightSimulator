#ifndef SHADERS_H
#define SHADERS_H


namespace Crunch
{

class Shaders
{
public:
    static inline const char* vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;
        layout (location = 1) in vec2 aTex;

        out vec2 textureCoords;

        uniform mat4 view;
        uniform mat4 model;
        uniform mat4 projection;

        void main()
        {
            gl_Position = projection * view * model * vec4(aPos, 1.0);
            textureCoords = aTex;
        }
    )";

    static inline const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        in vec2 textureCoords;

        uniform vec4 meshColor;
        uniform sampler2D meshTexture;
        uniform bool useTexture;

        void main()
        {
            if (useTexture) {
                FragColor = texture(meshTexture, textureCoords);
            } else {
                FragColor = meshColor;
            }
        }
    )";
};

}


#endif      // SHADERS_H
