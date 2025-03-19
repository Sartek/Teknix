#include "Game.hpp"

int Game::Start()
{
    Game::Window.create(sf::VideoMode({800,600},32),"Teknix",sf::Style::Close);
    Game::Window.setFramerateLimit(60);
    Game::Exiting = false;
    Game::Active = true;
    Game::Scale = 32;
    Game::Textures.loadTexture("../res/Box.png");
    Game::Textures.loadTexture("../res/Ground.png");
    Game::Textures.loadTexture("../res/Player.png");

    Game::player = new Player(b2Vec2(128,128),"../res/Player.png");

    Game::LoadLevel();

	Game::ft = sf::seconds(0);
	Game::at = 0;
	Game::dt =  1 / 120.0;

    Game::GameLoop();

    return 0;
}

void Game::LoadLevel()
{

    for(unsigned int i=16;i < 800;i+=32) {
        Game::GameLevel.newBlock(i,600-16,32,32,"../res/Ground.png");
    }
    //Game::GameLevel.newBlock(400,600-16,800,32,"../res/Ground.png");

    for(int i=16;i < 600;i+=32) {
        Game::GameLevel.newBlock(-16,i,32,32,"../res/Ground.png");
        Game::GameLevel.newBlock(816,i,32,32,"../res/Ground.png");
    }
}

void Game::GameLoop()
{
    while(!Game::isExiting())
    {
        Game::PollEvent();
        if (Game::isActive())
        {
            Game::ft = Game::dc.restart();
            if (Game::ft.asSeconds() > 0.25)
                Game::ft = sf::seconds(0.25); // Avoid spiral of death

            Game::at += Game::ft.asSeconds();

            Game::Update();
            while(Game::at >= Game::dt)
            {
                Game::Physics();
                Game::at -= dt;
            }
        }
        else
        {
            Game::dc.restart();
        }

        Game::UpdateSprites();
        Game::Render();
    }
}

void Game::PollEvent()
{
    while (const std::optional event = Game::Window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            Game::Exiting = true;
        if (event->is<sf::Event::FocusLost>())
            Game::Active = false;
        if (event->is<sf::Event::FocusGained>())
            Game::Active = true;
    }

    Game::Mouse.Update();
}

void Game::Update()
{
        if (Mouse.left() && !Mouse.lastleft())
        {
            GameObjects.newGameObject(Game::Mouse.X(), Game::Mouse.Y(),"../res/Box.png");
        }
        Game::player->Update();
}

void Game::Physics()
{
    Game::World.Step(Game::dt, 8, 3);
}

void Game::UpdateSprites()
{
    Game::GameLevel.UpdateSprites();
    Game::GameObjects.UpdateSprites();
    Game::player->UpdateSprite();
}

void Game::Render()
{
    Game::Window.clear(sf::Color(52, 72, 102));
    Game::GameLevel.DrawObjects();
    Game::GameObjects.DrawObjects();
    Game::player->Draw();
    Game::Window.display();
}

bool Game::isExiting()
{
    return Exiting;
}

bool Game::isActive()
{
    return Active;
}

b2World& Game::getWorld()
{
    return Game::World;
}

sf::RenderWindow& Game::getWindow()
{
    return Game::Window;
}

sf::Texture& Game::getTexture(std::string texture)
{
    return Textures.getTexture(texture);
}

int Game::getScale()
{
    return Scale;
}

sf::RenderWindow Game::Window;
bool Game::Exiting;
bool Game::Active;
int Game::Scale;
b2World Game::World(b2Vec2(0.f,9.8f));
Player* Game::player;
TextureManager Game::Textures;
ObjectManager Game::GameObjects;
Level Game::GameLevel;
MouseWrapper Game::Mouse;
float Game::dt;
float Game::at;
sf::Time Game::ft;
sf::Clock Game::dc;
