#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
    _column = 0;

    _blockLength = RoadBlock::BLOCK_LENGTH;

    _mapName = _game->getLevel() + ".map";

    _inputManager = _game->getInputManager();
    
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
    if(_game->isEditing())
    {
        handleInput();
    }
}

void Road::handleInput()
{
    if(_inputManager->isNewKey(InputManager::UP) && getRow() < _length - 1)
        _game->moveCamera(_blockLength);
    if(_inputManager->isNewKey(InputManager::DOWN) && getRow() > 0)
        _game->moveCamera(-_blockLength);
    if(_inputManager->isNewKey(InputManager::LEFT) && _column > 0)
        --_column;
    if(_inputManager->isNewKey(InputManager::RIGHT) && _column < LANES - 1)
        ++_column;

    int row = (int)getRow();

    if(_inputManager->isKeyPressed(InputManager::NUM0))
    {
        _map[row][_column] = 0;
        _blocks[row][_column]->setType(0);
    }
    else if(_inputManager->isKeyPressed(InputManager::NUM1))
    {
        _map[row][_column] = 1;
        _blocks[row][_column]->setType(1);
    }
    else if(_inputManager->isKeyPressed(InputManager::NUM2))
    {
        _map[row][_column] = 2;
        _blocks[row][_column]->setType(2);
    }

    if(_inputManager->isNewKey(InputManager::SAVE))
        writeMap();
}

float Road::getRow()
{
    float row = (_game->getCameraPosition() + 50) / _blockLength;

    if(row < 0)
        return 0;
    else
        return row;
}

int Road::getColumn()
{
    return _column;
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

void Road::writeMap()
{
    ofstream mapStream("../res/maps/" + _mapName);
    
    if(!mapStream)
    {
        cerr << "Failed to open file " << _mapName << endl;
        exit(EXIT_FAILURE);
    }

    mapStream << _length << endl;

    for(int i = 0; i < _length; ++i)
    {
        for(int j = 0; j < LANES; ++j)
        {
            if(j != LANES - 1)
                mapStream << _map[i][j] << " ";
            else
                mapStream << _map[i][j] << endl;
        }
    }

    mapStream.close();
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

    bool special[13][20];
    for(int i = 0; i < 13; i++)
        for(int j = 0; j < 20; j++)
            special[i][j] = false;

    for(int i = 0; i < 13; i++)
        //special[0][i] = true;
    _blocks[0][0]->drawSpecial(0, 0, special);
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
    float row = getRow();

    if(row > _length - 1)
        return false;
    else
        return _blocks[row][lane]->isSolid();
}
