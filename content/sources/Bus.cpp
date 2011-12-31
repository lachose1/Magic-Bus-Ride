#include "Bus.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Bus::IMAGE_NAME = "bowser.png";

Bus::Bus(Game* game) : SpriteComponent(game, IMAGE_NAME)
{
    _speed = 0;
    _score = 0;
    _jumpElapsed = 0;
    _jumping = false;

    _inputManager = _game->getInputManager();

    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling1on5"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling2on5"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling3on5"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling4on5"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling5on5"));

    _lane = CENTER;
    setSubRect();

    _position = Vector2f(_app->GetWidth()/2.0f - _sprite.GetSize().x/2.0f,
    _app->GetHeight() - _sprite.GetSize().y);

    _sprite.SetPosition(_position);
}

Bus::~Bus()
{
}

void Bus::update()
{
    float x = _position.x;

    if(_inputManager->isKeyPressed(InputManager::UP) && (_speed + ACCELERATION) <= MAX_SPEED)
        _speed += ACCELERATION;
    if(_inputManager->isKeyPressed(InputManager::DOWN) && _speed >= ACCELERATION)
        _speed -= ACCELERATION;
    if(_inputManager->isKeyPressed(InputManager::LEFT))
        x -= SPEED_X;
    if(_inputManager->isKeyPressed(InputManager::RIGHT))
        x += SPEED_X;
    if(_inputManager->isNewKey(InputManager::SPACE) && !_jumping)
        _jumping = true;

    if(isInBounds(x))
    {
        _position.x = x;
        _sprite.SetPosition(_position);
        setLane();
        setSubRect();
    }

    if(_jumping)
        jump();
}

void Bus::jump()
{
    float y = _position.y;

    if(_jumpElapsed < JUMP_DURATION / 2)
    {
        y -= JUMP_SPEED;
        ++_jumpElapsed;
    }
    else if(_jumpElapsed < JUMP_DURATION)
    {
        y += JUMP_SPEED;
        ++_jumpElapsed;
    }
    else
    {
        _jumping = false;
        _jumpElapsed = 0;
    }

    _position.y = y;
    _sprite.SetPosition(_position);
}

void Bus::setLane()
{
    int laneNumber = (int)(_sprite.GetPosition().x + _sprite.GetSize().x) / LANE_WIDTH;

    switch(laneNumber)
    {
    case 0:
        _lane = LEFT_EDGE;
        break;
    case 1:
        _lane = LEFT;
        break;
    case 2:
        _lane = CENTER;
        break;
    case 3:
        _lane = RIGHT;
        break;
    case 4:
        _lane = RIGHT_EDGE;
        break;
    default:
        _lane = CENTER;
        break;
    }
}

void Bus::setSubRect()
{
    _sprite.SetSubRect(*(_animations[_lane]->nextFrame()));
}

bool Bus::isInBounds(float x)
{
    return x >= 0 && (x + _sprite.GetSize().x) <= _app->GetWidth();
}

bool Bus::isAnimated()
{
    return _speed > 0;
}

bool Bus::isJumping()
{
    return _jumping;
}

Bus::Lane Bus::getLane()
{
    return _lane;
}

int Bus::getSpeed()
{
    return _speed;
}

int Bus::getScore()
{
    return _score;
}
