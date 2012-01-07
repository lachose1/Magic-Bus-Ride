#include "DrawableComponent.hpp"
#include "Game.hpp"

DrawableComponent::DrawableComponent(Game* game) : Component(game)
{
    _app = _game->getApp();
}

DrawableComponent::~DrawableComponent()
{
}

sf::Vector2f* DrawableComponent::getPosition()
{
	return 0;
}

void DrawableComponent::getSize()
{
}