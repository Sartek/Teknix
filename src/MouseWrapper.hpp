#ifndef MOUSEWRAPPER
#define MOUSEWRAPPER

#include <SFML/Window/Mouse.hpp>

class MouseWrapper
{
public:
    MouseWrapper();
    ~MouseWrapper();
    int X();
    int Y();
    bool left();
    bool lastleft();
    bool right();
    bool lastright();
    void Update();
private:
    int x;
    int y;
    bool LEFT;
    bool LLEFT;
    bool RIGHT;
    bool LRIGHT;
};
#endif // MouseWrapper
