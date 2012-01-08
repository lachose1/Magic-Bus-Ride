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
	_selector.SetPosition(_elements[0]->getPosition()->x - 75.f, _elements[0]->getPosition()->y + _selector.GetImage()->GetHeight()/2);
	_selectorChoice = 0;
	_maxChoices = _elements.size();
	_inputManager = _game->getInputManager();
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
	if(_inputManager->isNewKey(InputManager::UP) && _selectorChoice > 0)
		_selectorChoice--;
	if(_inputManager->isNewKey(InputManager::DOWN) && _selectorChoice < _maxChoices-1)
		_selectorChoice++;
	_selector.SetPosition(_elements[_selectorChoice]->getPosition()->x - 75.f, _elements[_selectorChoice]->getPosition()->y + _selector.GetImage()->GetHeight()/2);
}