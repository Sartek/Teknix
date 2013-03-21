#include "Level.hpp"
#include "Game.hpp"
Level::Level()
{

}

Level::~Level()
{

}

void Level::newBlock(float x,float y,int w,int h,std::string texture)
{
    Block* block = new Block(b2Vec2(x,y),b2Vec2(w,h),texture);
    levelBlocks.push_back(block);
}

void Level::UpdateSprites()
{
    for(unsigned int i=0;i < levelBlocks.size();i++) {
        levelBlocks.at(i)->UpdateSprite();
    }
}

void Level::DrawObjects()
{
    for(unsigned int i=0;i < levelBlocks.size();i++) {
        levelBlocks.at(i)->Draw();
    }
}
