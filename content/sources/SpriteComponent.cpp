#include "SpriteComponent.hpp"
#include "Game.hpp"

using namespace std;

SpriteComponent::SpriteComponent(Game* game, string filename) : DrawableComponent(game)
{
    _image = _game->getImageManager()->find(filename);
    _sprite.SetImage(*_image);
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::draw()
{
    _app->Draw(_sprite);
}
