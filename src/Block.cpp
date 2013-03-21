#include "Block.hpp"
#include "Game.hpp"

Block::Block(b2Vec2 Position,b2Vec2 Size,std::string texture)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(Position.x/Game::getScale(), Position.y/Game::getScale());
    BodyDef.type = b2_staticBody;
    Block::PhysicsObject = Game::getWorld().CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((Size.x/2)/Game::getScale(), (Size.y/2)/Game::getScale());
    b2FixtureDef FixtureDef;
    FixtureDef.density = 0.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    Block::PhysicsObject->CreateFixture(&FixtureDef);

    Block::setTexture(texture);
    SpriteObject.setOrigin(Size.x/2,Size.y/2);
}

Block::~Block()
{

}

b2Vec2 Block::getPosition()
{
    return Block::PhysicsObject->GetPosition();
}

sf::Sprite Block::getSprite()
{
    return Block::SpriteObject;
}

void Block::setTexture(std::string texture)
{
    Block::Texture = texture;
    Block::SpriteObject.setTexture(Game::getTexture(Block::Texture));
}

void Block::UpdateSprite()
{
    Block::SpriteObject.setPosition(Block::getPosition().x * Game::getScale(),Block::getPosition().y * Game::getScale());
    SpriteObject.setRotation(PhysicsObject->GetAngle() * 180/b2_pi);
}

void Block::Draw()
{
    Game::getWindow().draw(Block::getSprite());
}
