#ifndef OBJECTMANAGER
#define OBJECTMANAGER

#include <vector>
#include "GameObject.hpp"
#include <string>

class ObjectManager
{
public:
    ObjectManager();
    ~ObjectManager();
    unsigned int newGameObject(float x,float y,std::string texture);
    void UpdateSprites();
    void DrawObjects();
private:
    std::vector<GameObject*> objectList;
};
#endif // OBJECTMANAGER
