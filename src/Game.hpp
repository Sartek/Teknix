#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Block.hpp"
#include "Player.hpp"
#include "Level.hpp"
#include "TextureManager.hpp"
#include "ObjectManager.hpp"
#include "MouseWrapper.hpp"

class Game
{
public:
    static int Start();
    static b2World& getWorld();
    static sf::RenderWindow& getWindow();
    static int getScale();
    static sf::Texture& getTexture(std::string texture);
private:
    static void GameLoop();
    static void LoadLevel();
    static bool isExiting();
    static void PollEvent();
    static void Update();
    static void Physics();
    static void UpdateSprites();
    static void Render();
    static sf::RenderWindow Window;
    static bool Exiting;
    static int Scale;
    static b2World World;
    static TextureManager Textures;
    static ObjectManager GameObjects;
    static Level GameLevel;
    static Player* player;
    static MouseWrapper Mouse;
    static float dt;
    static float at;
    static sf::Time ft;
    static sf::Clock dc;
};
#endif // GAME
