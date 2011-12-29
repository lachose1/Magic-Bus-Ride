#ifndef DRAWABLE_COMPONENT_H
#define DRAWABLE_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Game;

class DrawableComponent : public Component
{
public :

    virtual sf::Sprite* draw() = 0;
    DrawableComponent(Game* game);
    ~DrawableComponent();
    
protected :

    sf::Image* _image; //Pointeur sur l'Image associee
    sf::Sprite _sprite; //Sprite associee

private :
    
};

#endif