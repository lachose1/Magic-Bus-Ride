#include "Menu.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

Menu::Menu(Game* game, string logo, float positionX, float positionY, vector<DrawableComponent*> elements) : Component(game)
{
	_position.x = positionX;
	_position.y = positionY;
}

Menu::~Menu()
{
}