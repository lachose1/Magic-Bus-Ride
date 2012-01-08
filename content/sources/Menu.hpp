#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "DrawableComponent.hpp"
#include "Animation.hpp"
#include "InputManager.hpp"

class Game;

class Menu : public Component
{
public :

	Menu(Game* game, std::string logo, float positionX, float positionY, std::vector<DrawableComponent*> elements);
    ~Menu();
	void draw();
	void update();
    
private :

	sf::Vector2f _position;
	std::vector<DrawableComponent*> _elements;
	sf::RenderWindow* _app;
	sf::Image* _logoImage;
	sf::Sprite _logoSprite;
	sf::Sprite _selector;
	Animation* _selectorAnimation;
	int _selectorChoice;
	unsigned int _maxChoices;
	InputManager* _inputManager;
};

#endif
