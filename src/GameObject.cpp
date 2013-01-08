#include "GameObject.hpp"
#include "Game.hpp"

GameObject::GameObject(b2Vec2 Position,std::string texture)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(Position.x/Game::getScale(), Position.y/Game::getScale());
    BodyDef.type = b2_dynamicBody;
    GameObject::PhysicsObject = Game::getWorld().CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((32.f/2)/Game::getScale(), (32.f/2)/Game::getScale());
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    GameObject::PhysicsObject->CreateFixture(&FixtureDef);

    GameObject::setTexture(texture);
    SpriteObject.setOrigin(16.f, 16.f);
}

GameObject::~GameObject()
{

}

b2Vec2 GameObject::getPosition()
{
    return GameObject::PhysicsObject->GetPosition();
}

sf::Sprite GameObject::getSprite()
{
    return GameObject::SpriteObject;
}

void GameObject::setTexture(std::string texture)
{
    GameObject::Texture = texture;
    GameObject::SpriteObject.setTexture(Game::getTexture(GameObject::Texture));
}

void GameObject::UpdateSprite()
{
    GameObject::SpriteObject.setPosition(GameObject::getPosition().x * Game::getScale(),GameObject::getPosition().y * Game::getScale());
    SpriteObject.setRotation(PhysicsObject->GetAngle() * 180/b2_pi);
}
