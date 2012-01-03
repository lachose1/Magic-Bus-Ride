#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
    _mapName = _game->getLevel() + ".map";
    loadMap();
    _blockTest = new RoadBlock(_game, 0, 1);
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
    for(int i = 0; i < 1; i++)
    {
        _blockTest->draw(0, 1);
        _blockTest->draw(0, 2);
        _blockTest->draw(0, 3);
    }
}