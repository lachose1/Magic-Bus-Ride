#ifndef ROADBLOCK_H
#define ROADBLOCK_H

#include "OpenGLComponent.hpp"

class RoadBlock : public OpenGLComponent
{
public :

    RoadBlock(Game* game, int type, float height = 5.f);
    ~RoadBlock();
    bool isSolid();
    void draw(int x, int y);
    void update();

private :

    int _type;
    float _height;
    bool _solid;
    static const float BLOCK_WIDTH;
    static const float BLOCK_LENGTH;
};

#endif