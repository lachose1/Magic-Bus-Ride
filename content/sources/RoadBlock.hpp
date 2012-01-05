#ifndef ROADBLOCK_H
#define ROADBLOCK_H

#include "OpenGLComponent.hpp"

class RoadBlock : public OpenGLComponent
{
public :
    static const float BLOCK_WIDTH;
    static const float BLOCK_LENGTH;
    enum Type {HOLE, ROAD, GRASS};

    RoadBlock(Game* game, int type, float height = 5.f);
    ~RoadBlock();
    bool isSolid();
    void draw(int x, int y);
    void update();
    float getBlockLength();

private :

    Type _type;
    float _height;
    bool _solid;
    int _texture;
    int _textureWidth;
    int _textureHeight;

};

#endif
