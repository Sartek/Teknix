#ifndef TEXTUREMANAGER
#define TEXTUREMANAGER

#include <map>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class TextureManager
{
private:
    //std::vector<sf::Texture> textureList;
    std::vector<std::string> loadedTextures;
    std::map<std::string, sf::Texture> textureList;
public:
    TextureManager();
    ~TextureManager();

    void loadTexture(std::string texture);
    sf::Texture& getTexture(std::string texture);
};

#endif // TEXTUREMANAGER
