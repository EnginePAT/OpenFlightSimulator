#ifndef SHADERLOADER_HPP
#define SHADERLOADER_HPP


#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Crunch
{

class ShaderLoader
{
public:
    static unsigned int compileShader(GLenum type, const char* source);
    static unsigned int compileShaderProgram(unsigned int vertShader, unsigned int fragShader);
};

};


#endif
