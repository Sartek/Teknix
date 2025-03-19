#include "Player.hpp"
#include "Game.hpp"
#include <iostream>

Player::Player(b2Vec2 Position,std::string texture) :
    SpriteObject(Game::getTexture(texture))
{
    jumpTimeout = 0;

    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(Position.x/Game::getScale(), Position.y/Game::getScale());
    BodyDef.type = b2_dynamicBody;
    BodyDef.fixedRotation = true;
    Player::PhysicsObject = Game::getWorld().CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((32.f/2)/Game::getScale(), (48.f/2)/Game::getScale());

    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    Player::PhysicsObject->CreateFixture(&FixtureDef);

    b2PolygonShape polygoneShape;
    polygoneShape.SetAsBox(0.03125, 0.03125, b2Vec2(0,(48.f/2)/Game::getScale()), 0);
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape= &polygoneShape;
    myFixtureDef.density = 1;
    myFixtureDef.isSensor = true;
    Player::SensorObject = Player::PhysicsObject->CreateFixture(&myFixtureDef);
    //Player::SensorObject->SetUserData((void*)3);
    //fix this
    Player::SensorObject->GetUserData().pointer = (uintptr_t)3;

    Player::setTexture(texture);
    SpriteObject.setOrigin({16.f, 24.f});
    Player::TextureRect = SpriteObject.getTextureRect();

    Player::ContactListener = new MyContactListener;
    ContactListener->initialize();
    Game::getWorld().SetContactListener(ContactListener);

    Player::Direction= 1;
}

Player::~Player()
{

}

b2Vec2 Player::getPosition()
{
    return Player::PhysicsObject->GetPosition();
}

sf::Sprite Player::getSprite()
{
    return Player::SpriteObject;
}

void Player::setTexture(std::string texture)
{
    Player::Texture = texture;
    Player::SpriteObject.setTexture(Game::getTexture(Player::Texture));
}

// The flip function works well TODO MOVE THIS SHIT
void Player::Flip(sf::Sprite& sprite)
{
    if (Player::Direction==-1)
    {
        sprite.setTextureRect(
            sf::IntRect(
                {sprite.getTextureRect().size.x, //TODO left+width?
                0},
                {-sprite.getTextureRect().size.x,
                sprite.getTextureRect().size.y}
            )
        );
    }
    else
    {
        sprite.setTextureRect(Player::TextureRect);
    }
}

void Player::UpdateSprite()
{
    Player::SpriteObject.setPosition({Player::getPosition().x * Game::getScale(),Player::getPosition().y * Game::getScale()});
    SpriteObject.setRotation(sf::degrees(PhysicsObject->GetAngle() * 180/b2_pi));
}

void Player::Update()
{
    if(jumpTimeout > 0)
        jumpTimeout--;
    b2Vec2 vel = Player::PhysicsObject->GetLinearVelocity();
    float desiredVelx = 0;
    float desiredVely = 0;


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        desiredVelx += -5;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        desiredVelx += 5;
    }

    if(desiredVelx > 0 && Player::Direction != 1) {
            Player::Direction = 1;
            Player::Flip(Player::SpriteObject);
    } else if(desiredVelx < 0 && Player::Direction !=-1) {
            Player::Direction = -1;
            Player::Flip(Player::SpriteObject);
    }

    float velChangex = desiredVelx - vel.x;
    float impulsex = Player::PhysicsObject->GetMass() * velChangex;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && ContactListener->numFootContacts > 0 && jumpTimeout < 1 )
    {
        desiredVely = -5;
        float velChangey = desiredVely - vel.y;
        float impulsey = Player::PhysicsObject->GetMass() * velChangey;
        Player::PhysicsObject->ApplyLinearImpulse( b2Vec2(impulsex,impulsey), Player::PhysicsObject->GetWorldCenter(),true );
        jumpTimeout = 15;
    }
    else
    {
        Player::PhysicsObject->ApplyLinearImpulse( b2Vec2(impulsex,0), Player::PhysicsObject->GetWorldCenter(),true );
    }

}

void Player::Draw()
{
    Game::getWindow().draw(Player::getSprite());
}

