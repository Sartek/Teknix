#ifndef GAMEOBJECT
#define GAMEOBJECT
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class GameObject
{
public:
    GameObject(b2Vec2 Position,std::string texture);
    virtual ~GameObject();
    b2Vec2 getPosition();
    sf::Sprite getSprite();
    void setTexture(std::string texture);
    void UpdateSprite();
private:
    sf::Sprite SpriteObject;
    std::string Texture;
    b2Body* PhysicsObject;
};

#endif // GAMEOBJECT
