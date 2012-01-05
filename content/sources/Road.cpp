#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
    _mapName = _game->getLevel() + ".map";
    
    ifstream mapStream("../res/maps/" + _mapName);
    
    if(!mapStream)
    {
        cerr << "Failed to open file " << _mapName << endl;
        exit(EXIT_FAILURE);
    }
    
    readLength(mapStream);
    _map = vector< std::vector<int> > (_length, vector<int>(LANES, 0));
    loadMap(mapStream);

    mapStream.close();

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

float Road::getRow()
{
    return _game->getCameraPosition() / _blockLength;
}

int Road::getLength()
{
    return _length;
}

void Road::readLength(ifstream& stream)
{
    stream >> _length;
}

void Road::loadMap(ifstream& stream)
{
    for(int i = 0; i < _length; ++i)
        for(int j = 0; j < LANES; ++j)
            stream >> _map[i][j];
}

void Road::createRoad()
{
    RoadBlock* blockContainer;
    unsigned int size = _map.size();

    for(unsigned int i = 0; i < size; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            blockContainer = new RoadBlock(_game, _map[i][j]);
            blockContainer->draw(j, i);
        }
    }
    _blockLength = blockContainer->getBlockLength();
    delete blockContainer;
}