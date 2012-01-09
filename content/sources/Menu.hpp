#ifndef MENU_H
#define MENU_H

#include "DrawableComponent.hpp"
#include "Animation.hpp"
#include "InputManager.hpp"

class Game;

class Menu : public DrawableComponent
{
public :

	Menu(Game* game, std::string logo, float positionX, float positionY, std::vector<DrawableComponent*> elements, std::vector<std::string> actions);
    ~Menu();
	void draw();
	void update();
	void matchChoice();
    
private :

	sf::Vector2f _position;
	std::vector<DrawableComponent*> _elements;
	std::vector<std::string> _actions;
	sf::RenderWindow* _app;
	sf::Image* _logoImage;
	sf::Sprite _logoSprite;
	sf::Sprite _selector;
	Animation* _selectorAnimation;
	unsigned int _selectorChoice;
	unsigned int _maxChoices;
	InputManager* _inputManager;
    static const int MARGIN_X = 75;
};

#endif
