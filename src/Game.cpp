#include "Game.hpp"

int Game::Start()
{
    Game::Window.create(sf::VideoMode(800,600,32),"Teknix",sf::Style::Close);
    Game::Window.setFramerateLimit(60);
    Game::Exiting = false;
    Game::Scale = 32;
    Game::Textures.loadTexture("../res/Box.png");
    Game::Textures.loadTexture("../res/Ground.png");

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
    for(int i=16;i < 600;i+=32) {
        Game::GameLevel.newBlock(-16,i,32,32,"../res/Ground.png");
        Game::GameLevel.newBlock(816,i,32,32,"../res/Ground.png");
    }
}

void Game::GameLoop()
{
    while(!Game::isExiting())
    {
    	Game::ft = Game::dc.restart();
    	if (Game::ft.asSeconds() > 0.25)
			Game::ft = sf::seconds(0.25); // Avoid spiral of death

		Game::at += Game::ft.asSeconds();

        Game::PollEvent();
        Game::Update();
        while(Game::at >= Game::dt)
        {
			Game::Physics();
        	Game::at -= dt;
        }
        Game::UpdateSprites();
        Game::Render();
    }
}

void Game::PollEvent()
{
    sf::Event event;

    while (Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Game::Exiting = true;
    }

    Game::Mouse.Update();
}

void Game::Update()
{
        if (Mouse.left() && !Mouse.lastleft())
        {
            GameObjects.newGameObject(Game::Mouse.X(), Game::Mouse.Y(),"../res/Box.png");
        }
}

void Game::Physics()
{
    Game::World.Step(Game::dt, 8, 3);
}

void Game::UpdateSprites()
{
    Game::GameLevel.UpdateSprites();
    Game::GameObjects.UpdateSprites();
}

void Game::Render()
{
    Game::Window.clear(sf::Color(52, 72, 102));
    Game::GameLevel.DrawObjects();
    Game::GameObjects.DrawObjects();
    Game::Window.display();
}

bool Game::isExiting()
{
    return Exiting;
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
int Game::Scale;
b2World Game::World(b2Vec2(0.f,9.8f));
Block* Game::Box;
TextureManager Game::Textures;
ObjectManager Game::GameObjects;
Level Game::GameLevel;
MouseWrapper Game::Mouse;
float Game::dt;
float Game::at;
sf::Time Game::ft;
sf::Clock Game::dc;
