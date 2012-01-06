#ifndef MENU_H
#define MENU_H

#include "Component.hpp"
#include "DrawableComponent.hpp"

class Game;

class Menu : public Component
{
public :

    Menu(Game* game, std::string logo, float positionX, float positionY, std::vector<DrawableComponent*> elements);
    ~Menu();
    
private :

	sf::Vector2f _position;
};

#endif
