#include "TextureManager.hpp"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

void TextureManager::loadTexture(std::string texture)
{
    bool allowLoad = true;
    for(unsigned int i = 0; i<loadedTextures.size(); i++)
    {
        if(loadedTextures[i] == texture)
        {
            allowLoad = false;
            break;
        }
    }

    if(allowLoad)
    {
        sf::Texture temptexture;
        temptexture.loadFromFile(texture);
        loadedTextures.push_back(texture);
        textureList[texture] = temptexture;
    }
}

sf::Texture& TextureManager::getTexture(std::string texture)
{
    return textureList[texture];
}
