#ifndef BLOCK
#define BLOCK
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class Block
{
public:
    Block(b2Vec2 Position,b2Vec2 Size,std::string texture);
    virtual ~Block();
    b2Vec2 getPosition();
    sf::Sprite getSprite();
    void setTexture(std::string texture);
    void UpdateSprite();
    void Draw();
private:
    sf::Sprite SpriteObject;
    std::string Texture;
    b2Body* PhysicsObject;
};

#endif // BLOCK
