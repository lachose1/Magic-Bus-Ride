#ifndef ROADBLOCK_H
#define ROADBLOCK_H

#include "OpenGLComponent.hpp"

class RoadBlock : public OpenGLComponent
{
public :

    RoadBlock(Game* game, int type, int height);
    ~RoadBlock();
    bool isSolid();
    void draw(int x, int y);
    void update();

private :

    int _type;
    int _height;
    bool _solid;
};

#endif