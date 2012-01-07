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
	_selector.SetImage((*_game->getImageManager()->find("arrow.png")));
	_selectorAnimation = new Animation("../res/animations/arrow.ani", "moving");
	_selector.SetSubRect((*_selectorAnimation->nextFrame()));
	_selector.SetPosition(_elements[1]->getPosition()->x - 75.f, _elements[1]->getPosition()->y);
}

Menu::~Menu()
{
}

void Menu::draw()
{
	_app->Draw(_logoSprite);
	_app->Draw(_selector);
	for(unsigned int i = 0; i < _elements.size(); i++)
		_elements[i]->draw();
}

void Menu::update()
{
	_selector.SetSubRect((*_selectorAnimation->nextFrame()));
}