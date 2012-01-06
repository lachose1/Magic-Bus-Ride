#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
    _blockLength = RoadBlock::BLOCK_LENGTH;

    _mapName = _game->getLevel() + ".map";
    
    ifstream mapStream("../res/maps/" + _mapName);
    
    if(!mapStream)
    {
        cerr << "Failed to open file " << _mapName << endl;
        exit(EXIT_FAILURE);
    }
    
    readLength(mapStream);
    _map = vector< vector<int> > (_length, vector<int>(LANES, 0));
    loadMap(mapStream);

    mapStream.close();

    createRoad();
}

Road::~Road()
{
}

void Road::draw()
{
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, -50.f, _game->getCameraPosition());
        drawRoad();
		createEnvironment();
}

void Road::update()
{
}

float Road::getRow()
{
    float row = (_game->getCameraPosition() + 50) / _blockLength;
    if(row > 0)
        return row;
    else
        return 0;
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
    _blocks = vector< vector<RoadBlock*> > (_length, vector<RoadBlock*>(LANES));

    for(int i = 0; i < _length; ++i)
        for(int j = 0; j < LANES; ++j)
            _blocks[i][j] = new RoadBlock(_game, _map[i][j]);
}

void Road::drawRoad()
{
    int startingRow = getRow() - 1;

    if(startingRow < 0)
        startingRow = 0;

    for(int i = startingRow; i < MAX_ROWS + startingRow && i < _length; ++i)
        for(int j = 0; j < LANES; ++j)
            _blocks[i][j]->draw(j, i);
}

void Road::createEnvironment()
{
	int currentRow = getRow();

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

bool Road::isSolid(int lane)
{
    return _blocks[getRow()][lane]->isSolid();
}
