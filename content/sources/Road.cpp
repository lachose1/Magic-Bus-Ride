#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
    _mapName = _game->getLevel() + ".map";
    loadMap();
    _blockTest = new RoadBlock(_game, 1);
    _blockTest2 = new RoadBlock(_game, 2);
}

Road::~Road()
{
}

void Road::draw()
{
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, -50.f, _game->getCameraPosition());
        //glRotatef(20, 1.f, 0.f, 0.f); //Ces lignes sont temporaires, juste pour
        //glRotatef(_game->getTime() * 60, 1.f, 0.f, 0.f); //Ces lignes sont temporaires, juste pour
        //glRotatef(_game->getTime() * 30, 0.f, 1.f, 0.f); //bien tester l'animation OpenGL
        //glRotatef(_game->getTime() * 90, 0.f, 0.f, 1.f); //en faisant tourner le cube
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
    for(int i = 0; i < 200; i++)
    {
        _blockTest2->draw(0, 1+i);
        _blockTest->draw(1, 2+i);
        _blockTest->draw(1, 3+i);
        _blockTest->draw(1, 4+i);
        _blockTest->draw(1, 5+i);
        _blockTest2->draw(2, 3+i);
        _blockTest->draw(3, 4+i);
		_blockTest->draw(3, 0+i);
		_blockTest->draw(3, -1+i);
		_blockTest->draw(3, -2+i);
		_blockTest->draw(3, -3+i);
		_blockTest->draw(3, -4+i);
		_blockTest->draw(3, -5+i);
		_blockTest->draw(3, -6+i);
        _blockTest->draw(3, -7+i);
        _blockTest2->draw(4, 5+i);
        _blockTest->draw(5, 6+i);
        _blockTest2->draw(6, 7+i);
    }
}
