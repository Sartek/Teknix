#ifndef LEVEL
#define LEVEL
#include "Block.hpp"

class Level
{
public:
    Level();
    ~Level();
    void newBlock(float x,float y,int w,int h,std::string texture);
    void UpdateSprites();
    void DrawObjects();
private:
    std::vector<Block*> levelBlocks;
};

#endif // LEVEL
