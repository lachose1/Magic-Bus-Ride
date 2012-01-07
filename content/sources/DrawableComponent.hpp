#ifndef DRAWABLE_COMPONENT_H
#define DRAWABLE_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Game;

class DrawableComponent : public Component
{
public :

    virtual void draw() = 0;
	virtual sf::Vector2f* getPosition();
	virtual void getSize();
    DrawableComponent(Game* game);
    ~DrawableComponent();

protected:

    sf::RenderWindow* _app;
};

#endif