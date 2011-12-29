#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(Game* game) : DrawableComponent(game)
{
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::draw()
{
    _app->Draw(_sprite);
}
