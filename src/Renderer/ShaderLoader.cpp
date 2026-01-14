#include <Renderer/ShaderLoader.hpp>

unsigned int ShaderLoader::compileShader(GLenum type, const char* source)
{
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    return shader;
}

unsigned int ShaderLoader::compileShaderProgram(unsigned int vertShader, unsigned int fragShader)
{
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return shaderProgram;
}
