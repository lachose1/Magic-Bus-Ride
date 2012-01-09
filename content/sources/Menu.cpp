#include "Menu.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

Menu::Menu(Game* game, string logo, float positionX, float positionY, vector<DrawableComponent*> elements, vector<string> actions) : Component(game), _elements(elements), _actions(actions)
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
	_selector.SetPosition(_elements[0]->getPosition()->x - 75.f, _elements[0]->getPosition()->y + _elements[0]->getSize()->y/2 - _selector.GetImage()->GetHeight()/2);
	_selectorChoice = 0;
	_maxChoices = _elements.size();
	_inputManager = _game->getInputManager();
}

Menu::~Menu()
{
	delete _logoImage;
	delete _selectorAnimation;
	delete _app;
	delete _inputManager;
	unsigned int size = _elements.size();
	for(unsigned int i = 0; i < size; i++)
	{
        delete _elements[i];
        _elements[i] = 0;
    }
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
	if(_inputManager->isNewKey(InputManager::ENTER))
		matchChoice();
	_selector.SetSubRect((*_selectorAnimation->nextFrame()));
	if(_inputManager->isNewKey(InputManager::UP) && _selectorChoice > 0)
		_selectorChoice--;
	if(_inputManager->isNewKey(InputManager::DOWN) && _selectorChoice < _maxChoices-1)
		_selectorChoice++;
	_selector.SetPosition(_elements[_selectorChoice]->getPosition()->x - 75.f, _elements[_selectorChoice]->getPosition()->y + _elements[0]->getSize()->y/2 - _selector.GetImage()->GetHeight()/2);
}

void Menu::matchChoice()
{
	_game->menuAction(_actions[_selectorChoice]);
}