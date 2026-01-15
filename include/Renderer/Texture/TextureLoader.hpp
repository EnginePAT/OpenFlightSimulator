#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP


#include <glad/glad.h>
#include <stb/stb_image.h>
#include <string>
#include <iostream>


namespace Crunch
{

class TextureLoader
{
public:
    static unsigned int loadTexture(const std::string& path, int& width, int& height, int& channels);
};

};


#endif      // TEXTURELOADER_HPP
