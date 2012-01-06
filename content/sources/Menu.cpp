#include "Menu.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

Menu::Menu(Game* game, string logo, float positionX, float positionY, vector<DrawableComponent*> elements) : Component(game), _elements(elements)
{
	_position.x = positionX;
	_position.y = positionY;
	_app = _game->getApp();
	_logoImage = _game->getImageManager()->find(logo);
	_logoSprite.SetImage(*(_logoImage));
	_logoSprite.SetPosition(_position.x-_logoImage->GetWidth()/2, _position.y);
}

Menu::~Menu()
{
}

void Menu::draw()
{
	_app->Draw(_logoSprite);
	for(unsigned int i = 0; i < _elements.size(); i++)
		_elements[i]->draw();
}

void Menu::update()
{
}