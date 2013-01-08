#include "MouseWrapper.hpp"
#include "Game.hpp"

MouseWrapper::MouseWrapper()
{
    MouseWrapper::LLEFT = false;
    MouseWrapper::LEFT = false;
    MouseWrapper::LRIGHT = false;
    MouseWrapper::RIGHT = false;
    MouseWrapper::x = 0;
    MouseWrapper::y = 0;
}
MouseWrapper::~MouseWrapper()
{

}
int MouseWrapper::X()
{
    return MouseWrapper::x;
}
int MouseWrapper::Y()
{
    return MouseWrapper::y;
}
bool MouseWrapper::left()
{
    return MouseWrapper::LEFT;
}
bool MouseWrapper::lastleft()
{
    return MouseWrapper::LLEFT;
}
bool MouseWrapper::right()
{
    return MouseWrapper::RIGHT;
}
bool MouseWrapper::lastright()
{
    return MouseWrapper::LRIGHT;
}
void MouseWrapper::Update()
{
    MouseWrapper::LLEFT = MouseWrapper::LEFT;
    MouseWrapper::LRIGHT = MouseWrapper::RIGHT;
    MouseWrapper::LEFT = sf::Mouse::isButtonPressed((sf::Mouse::Left));
    MouseWrapper::RIGHT = sf::Mouse::isButtonPressed((sf::Mouse::Right));
    MouseWrapper::x = sf::Mouse::getPosition(Game::getWindow()).x;
    MouseWrapper::y = sf::Mouse::getPosition(Game::getWindow()).y;
}
