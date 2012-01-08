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

sf::Vector2f* DrawableComponent::getSize()
{
	return 0;
}