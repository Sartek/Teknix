#ifndef PLAYER
#define PLAYER
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "MyContactListener.hpp"


class Player
{
public:
    Player(b2Vec2 Position,std::string texture);
    virtual ~Player();
    b2Vec2 getPosition();
    sf::Sprite getSprite();
    void setTexture(std::string texture);
    void UpdateSprite();
    void Update();
    void Draw();
private:
    sf::Sprite SpriteObject;
    std::string Texture;
    int jumpTimeout;
    b2Body* PhysicsObject;
    b2Fixture* SensorObject;
    MyContactListener* ContactListener;
};

#endif // PLAYER
