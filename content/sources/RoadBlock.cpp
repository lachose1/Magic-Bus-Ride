#include "RoadBlock.hpp"
#include "Game.hpp"

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

    glBegin(GL_QUADS);
        
        //Front
        glVertex3f(-25.f,  10.f,  0.f-y);
        glVertex3f( 25.f,  10.f,  0.f-y);
        glVertex3f( 25.f, -10.f,  0.f-y);
        glVertex3f(-25.f, -10.f,  0.f-y);

        //Right
        glVertex3f( 25.f,  10.f,  0.f-y);
        glVertex3f( 25.f,  10.f, -10.f-y);
        glVertex3f( 25.f, -10.f, -10.f-y);
        glVertex3f( 25.f, -10.f,  0.f-y);
        
        //Back
        glVertex3f( 25.f,  10.f, -10.f-y);
        glVertex3f(-25.f,  10.f, -10.f-y);
        glVertex3f(-25.f, -10.f, -10.f-y);
        glVertex3f( 25.f, -10.f, -10.f-y);

        //Left
        glVertex3f(-25.f,  10.f, -10.f-y);
        glVertex3f(-25.f,  10.f,  0.f-y);
        glVertex3f(-25.f, -10.f,  0.f-y);
        glVertex3f(-25.f, -10.f, -10.f-y);
        
        //Top
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-25.f,  10.f, -10.f-y);
        glTexCoord2f(1.0f, 0.5f);
        glVertex3f( 25.f,  10.f, -10.f-y);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f( 25.f,  10.f,  0.f-y);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-25.f,  10.f,  0.f-y);

        //Bottom
        glVertex3f(-25.f, -10.f,  0.f-y);
        glVertex3f( 25.f, -10.f,  0.f-y);
        glVertex3f( 25.f, -10.f, -10.f-y);
        glVertex3f(-25.f, -10.f, -10.f-y);

    glEnd();
}

void RoadBlock::update()
{
}