#include "Bus.hpp"

using namespace std;
using namespace sf;

Bus::Bus(Game* game, Image* image) : SpriteComponent(game)
{
    _image = image;
    _sprite.SetImage(*(_image));
}

Bus::~Bus()
{
}

void Bus::update()
{
    return;
}

Sprite* Bus::draw()
{
    return &_sprite;
}