#ifndef DRAWABLE_COMPONENT_H
#define DRAWABLE_COMPONENT_H

#include "Component.hpp"

class Game;

class DrawableComponent : public Component
{
public :

    virtual void draw() = 0;
    DrawableComponent(Game* game);
    ~DrawableComponent();
    
protected :

private :
    sf::Image* _image; //Pointeur sur l'Image associee
    sf::Sprite _sprite; //Sprite associee
};

#endif