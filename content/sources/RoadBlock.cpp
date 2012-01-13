#include "RoadBlock.hpp"
#include "Game.hpp"


const float RoadBlock::BLOCK_WIDTH = 13.f;
const float RoadBlock::BLOCK_LENGTH = 20.f;
const float RoadBlock::SPECIAL_BLOCK_WIDTH = 1.f;
const float RoadBlock::SPECIAL_BLOCK_LENGTH = 1.f;

RoadBlock::RoadBlock(Game* game, int type, float height) : OpenGLComponent(game), _height(height)
{
    setType(type);
}

RoadBlock::~RoadBlock()
{
}

void RoadBlock::setType(int type)
{
    if(type < 0 || type > 2)
        type = 0;

    _type = (Type)type;

    switch(_type)
    {
    case HOLE:
        _solid = false;
        break;
    case ROAD:
        _texture = _game->getTextureManager()->find("road2.png");
        _textureWidth = _game->getImageManager()->find("road2.png")->GetWidth();
        _textureHeight = _game->getImageManager()->find("road2.png")->GetHeight();
        _solid = true;
        break;
    case GRASS:
        _texture = _game->getTextureManager()->find("grass1.png");
        _textureWidth = _game->getImageManager()->find("grass1.png")->GetWidth();
        _textureHeight = _game->getImageManager()->find("grass1.png")->GetHeight();
        _solid = true;
        break;
    default:
        break;
    }
}

bool RoadBlock::isSolid()
{
    return _solid;
}

void RoadBlock::draw(int x, int y)
{
    if(_type == HOLE )
        return;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texture);

    float firstLaneX1 = BLOCK_WIDTH*3 - BLOCK_WIDTH/2;
    float firstLaneX2 = BLOCK_WIDTH*3 + BLOCK_WIDTH/2;
    float texturePointX = BLOCK_WIDTH*10 / _textureWidth;

    if(texturePointX < 1)
        texturePointX = 1;

    float texturePointY = BLOCK_LENGTH*10 / _textureHeight;

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
        glTexCoord2f(0.0f, texturePointY);
        glVertex3f(-firstLaneX1+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glTexCoord2f(texturePointX, texturePointY);
        glVertex3f(-firstLaneX2+x*BLOCK_WIDTH,  _height, -BLOCK_LENGTH-y*BLOCK_LENGTH);
        glTexCoord2f(texturePointX, 0.0f);
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

void RoadBlock::drawSpecial(int x, int y, bool* blocks[13][20])
{
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _texture);

    float firstLaneX1 = SPECIAL_BLOCK_WIDTH*3 - SPECIAL_BLOCK_WIDTH/2;
    float firstLaneX2 = SPECIAL_BLOCK_WIDTH*3 + SPECIAL_BLOCK_WIDTH/2;
    float texturePointX = SPECIAL_BLOCK_WIDTH*10 / _textureWidth;

    if(texturePointX < 1)
        texturePointX = 1;

    float texturePointY = SPECIAL_BLOCK_LENGTH*10 / _textureHeight;

	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 13; j++)
		{
			if(blocks[j][i])
			{
				glBegin(GL_QUADS);
        
					//Front
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH,  _height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH,  _height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH, -_height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH, -_height,  0.f-y*SPECIAL_BLOCK_LENGTH);

					//Right
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH,  _height,   0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH,  _height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH, -_height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH, -_height,   0.f-y*SPECIAL_BLOCK_LENGTH);
        
					//Back
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH,  _height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH,  _height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH, -_height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH, -_height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);

					//Left
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH,  _height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH,  _height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH, -_height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH, -_height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
        
					//Top
					glTexCoord2f(0.0f, texturePointY);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH,  _height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glTexCoord2f(texturePointX, texturePointY);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH,  _height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glTexCoord2f(texturePointX, 0.0f);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH,  _height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glTexCoord2f(0.0f, 0.0f);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH,  _height,  0.f-y*SPECIAL_BLOCK_LENGTH);

					//Bottom
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH, -_height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH, -_height,  0.f-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX2+x*SPECIAL_BLOCK_WIDTH, -_height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);
					glVertex3f(-firstLaneX1+x*SPECIAL_BLOCK_WIDTH, -_height, -SPECIAL_BLOCK_LENGTH-y*SPECIAL_BLOCK_LENGTH);

				glEnd();
			}
		}
}