#include "RoadBlock.hpp"
#include "Game.hpp"

const float RoadBlock::BLOCK_WIDTH = 50.f;

RoadBlock::RoadBlock(Game* game, int type, int height) : OpenGLComponent(game), _type(type), _height(height)
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
    glBindTexture(GL_TEXTURE_2D, _game->roadTexture);

    float firstLaneX1 = BLOCK_WIDTH*3 - BLOCK_WIDTH/2;
    float firstLaneX2 = BLOCK_WIDTH*3 + BLOCK_WIDTH/2;

    glBegin(GL_QUADS);
        
        //Front
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -5.f,  0.f-y*20.f);

        //Right
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  5.f,   0.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -5.f,   0.f-y*20.f);
        
        //Back
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -5.f, -20.f-y*20.f);

        //Left
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -5.f, -20.f-y*20.f);
        
        //Top
        glTexCoord2f(0.0f, 0.12f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  5.f, -20.f-y*20.f);
        glTexCoord2f(1.0f, 0.12f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  5.f, -20.f-y*20.f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  5.f,  0.f-y*20.f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  5.f,  0.f-y*20.f);

        //Bottom
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -5.f,  0.f-y*20.f);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH, -5.f, -20.f-y*20.f);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH, -5.f, -20.f-y*20.f);

    glEnd();
}

void RoadBlock::update()
{
}