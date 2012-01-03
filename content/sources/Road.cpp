#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
    _mapName = _game->getLevel() + ".map";
    loadMap();
}

Road::~Road()
{
}

void Road::draw()
{
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(_game->getTime() * 50, 1.f, 0.f, 0.f); //Ces lignes sont temporaires, juste pour
        glRotatef(_game->getTime() * 30, 0.f, 1.f, 0.f); //bien tester l'animation OpenGL
        glRotatef(_game->getTime() * 90, 0.f, 0.f, 1.f); //en faisant tourner le cube
        createRoad();
}

void Road::update()
{
}

void Road::loadMap()
{
    ifstream mapFile("../res/maps/" + _mapName);
    
    if(mapFile)
    {

    }
    mapFile.close();
}

void Road::createRoad()
{
    for(int i = 0; i < 150; i++)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _game->roadTexture);

        glBegin(GL_QUADS);
        
            //Front
            glVertex3f(-25.f,  10.f,  0.f-i*5);
            glVertex3f( 25.f,  10.f,  0.f-i*5);
            glVertex3f( 25.f, -10.f,  0.f-i*5);
            glVertex3f(-25.f, -10.f,  0.f-i*5);

            //Right
            glVertex3f( 25.f,  10.f,  0.f-i*5);
            glVertex3f( 25.f,  10.f, -10.f-i*5);
            glVertex3f( 25.f, -10.f, -10.f-i*5);
            glVertex3f( 25.f, -10.f,  0.f-i*5);

            //Back
            glVertex3f( 25.f,  10.f, -10.f-i*5);
            glVertex3f(-25.f,  10.f, -10.f-i*5);
            glVertex3f(-25.f, -10.f, -10.f-i*5);
            glVertex3f( 25.f, -10.f, -10.f-i*5);

            //Left
            glVertex3f(-25.f,  10.f, -10.f-i*5);
            glVertex3f(-25.f,  10.f,  0.f-i*5);
            glVertex3f(-25.f, -10.f,  0.f-i*5);
            glVertex3f(-25.f, -10.f, -10.f-i*5);

            //Top
            glTexCoord2f(0.0f, 0.5f);
            glVertex3f(-25.f,  10.f, -10.f-i*5);
            glTexCoord2f(1.0f, 0.5f);
            glVertex3f( 25.f,  10.f, -10.f-i*5);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f( 25.f,  10.f,  0.f-i*5);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-25.f,  10.f,  0.f-i*5);

            //Bottom
            glVertex3f(-25.f, -10.f,  0.f-i*5);
            glVertex3f( 25.f, -10.f,  0.f-i*5);
            glVertex3f( 25.f, -10.f, -10.f-i*5);
            glVertex3f(-25.f, -10.f, -10.f-i*5);

        glEnd();
    }
}