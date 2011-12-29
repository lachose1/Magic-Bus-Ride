#include "Bus.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Bus::IMAGE_NAME = "bus.png";

Bus::Bus(Game* game) : SpriteComponent(game, IMAGE_NAME)
{
    
    _position = Vector2f(_app->GetWidth()/2.0f - _image->GetWidth()/2.0f,
        _app->GetHeight() - _image->GetHeight());

    _sprite.SetPosition(_position);
}

Bus::~Bus()
{
}

void Bus::update()
{
    return;
}
