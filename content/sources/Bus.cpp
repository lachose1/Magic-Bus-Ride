#include "Bus.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Bus::IMAGE_NAME = "bus.png";

Bus::Bus(Game* game) : SpriteComponent(game, IMAGE_NAME)
{
    _speed = 0;
    _score = 0;

    _inputManager = _game->getInputManager();

    _position = Vector2f(_app->GetWidth()/2.0f - _image->GetWidth()/2.0f,
        _app->GetHeight() - _image->GetHeight());

    _sprite.SetPosition(_position);
}

Bus::~Bus()
{
}

void Bus::update()
{
    float x = _position.x;

    if(_inputManager->isKeyPressed(InputManager::UP))
        _speed += ACCELERATION;
    if(_inputManager->isKeyPressed(InputManager::DOWN) && _speed >= ACCELERATION)
        _speed -= ACCELERATION;
    if(_inputManager->isKeyPressed(InputManager::LEFT))
        x -= SPEED_X;
    if(_inputManager->isKeyPressed(InputManager::RIGHT))
        x += SPEED_X;

    if(isInBounds(x))
    {
        _position.x = x;
        _sprite.SetPosition(_position);
    }
}

int Bus::getSpeed()
{
    return _speed;
}

int Bus::getScore()
{
    return _score;
}

bool Bus::isInBounds(float x)
{
    return x >= 0 && (x + _image->GetWidth()) <= _app->GetWidth();
}
