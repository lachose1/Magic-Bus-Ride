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
}

Road::~Road()
{
}

void Road::draw()
{
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, -50.f, _game->getCameraPosition());
        createRoad();
		createEnvironment();
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
    int currentRow = getRow();
    if( currentRow < 0)
        currentRow = 0;
    for(unsigned int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            unsigned int nextBlock = i + currentRow;
            if(nextBlock >= size)
                nextBlock = size-1;
            blockContainer = new RoadBlock(_game, _map[nextBlock][j]);
            blockContainer->draw(j, nextBlock);
        }
    }
    _blockLength = blockContainer->getBlockLength();
    delete blockContainer;
}

void Road::createEnvironment()
{
	int currentRow = getRow();
    if( currentRow < 0)
        currentRow = 0;
	glBindTexture(GL_TEXTURE_2D, _game->getTextureManager()->find("skyscraper1.png"));
	for(int i = 0; i < 10; i++)
	{
        glBegin(GL_QUADS);

            //Skyscraper
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-70.f,  50.f, -100.f-i*40.f);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-50.f,  50.f, -100.f-i*40.f);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-50.f, -50.f, -100.f-i*40.f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-70.f, -50.f, -100.f-i*40.f);

			//Skyscraper
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(70.f,  50.f, -160.f-i*60.f);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(50.f,  50.f, -160.f-i*60.f);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(50.f, -50.f, -160.f-i*60.f);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(70.f, -50.f, -160.f-i*60.f);

        glEnd();
	}
}