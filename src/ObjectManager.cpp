#include "ObjectManager.hpp"
#include "Game.hpp"

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

unsigned int ObjectManager::newGameObject(float x,float y,std::string texture)
{
    GameObject* gameObject = new GameObject(b2Vec2(x,y),texture);
    objectList.push_back(gameObject);
    unsigned int id = objectList.size() - 1;
    return id;
}

void ObjectManager::UpdateSprites()
{
    for(unsigned int i=0;i < objectList.size();i++) {
        objectList.at(i)->UpdateSprite();
    }
}

void ObjectManager::DrawObjects()
{
    for(unsigned int i=0;i < objectList.size();i++) {
        objectList.at(i)->Draw();
    }
}
