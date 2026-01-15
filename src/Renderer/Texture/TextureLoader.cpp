#define STB_IMAGE_IMPLEMENTATION
#include <Renderer/Texture/TextureLoader.hpp>


namespace Crunch {

unsigned int TextureLoader::loadTexture(const std::string &path, int &width, int &height, int &channels)
{
    stbi_set_flip_vertically_on_load(true);

    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (!data)
    {
        std::cerr << "[ERROR]: Failed to load texture: '" << path << "'" << std::endl;
        return 0;
    }

    GLenum format = (channels == 3) ? GL_RGB : GL_RGBA;

    unsigned int textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}

};
