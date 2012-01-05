#include "RoadBlock.hpp"
#include "Game.hpp"


const float RoadBlock::BLOCK_WIDTH = 12.75f;
const float RoadBlock::BLOCK_LENGTH = 20.f;

RoadBlock::RoadBlock(Game* game, int type, float height) : OpenGLComponent(game), _type(type), _height(height)
{
}

RoadBlock::~RoadBlock()
{
}

bool RoadBlock::isSolid()
{
    return _solid;
}

void RoadBlock::draw(int x, int y)
{
    glEnable(GL_TEXTURE_2D);
    int texture;
    if(_type == 1)
        texture = _game->roadTexture;
    if(_type == 2)
        texture = _game->grassTexture;
    glBindTexture(GL_TEXTURE_2D, texture);

    float firstLaneX1 = BLOCK_WIDTH*3 - BLOCK_WIDTH/2;
    float firstLaneX2 = BLOCK_WIDTH*3 + BLOCK_WIDTH/2;


    glBegin(GL_QUADS);
        
        //Front
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -_height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -_height,  0.f-y*BLOCK_LENGTH);

        //Right
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height,   0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -_height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -_height,   0.f-y*BLOCK_LENGTH);
        
        //Back
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -_height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -_height, -BLOCK_LENGTH-y*BLOCK_LENGTH);

        //Left
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -_height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -_height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        
        //Top
        glTexCoord2f(0.0f, 0.12f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glTexCoord2f(1.0f, 0.12f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height,  0.f-y*BLOCK_LENGTH);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height,  0.f-y*BLOCK_LENGTH);

        //Bottom
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -_height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -_height,  0.f-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -_height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -_height, -BLOCK_LENGTH-y*BLOCK_LENGTH);

    glEnd();
}

void RoadBlock::update()
{
}