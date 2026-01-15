#ifndef TEXTURE_HPP
#define TEXTURE_HPP


#include <glad/glad.h>
#include <iostream>
#include <Renderer/Texture/TextureLoader.hpp>


namespace Crunch
{

class Texture : public TextureLoader
{
public:
    unsigned int id = 0;
    int width = 0;
    int height = 0;
    int channels = 0;

    Texture() = default;

    ~Texture()
    {
        if (id) glDeleteTextures(1, &id);
    }

    bool loadFromFile(const std::string& path);

    void bind(unsigned int slot = 0) const;
    void unbind() const;
};

};


#endif          // TEXTURE_HPP
