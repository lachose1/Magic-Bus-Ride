#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "DrawableComponent.hpp"

class SpriteComponent : public DrawableComponent
{
public :

    SpriteComponent(Game* game, std::string filename);
    ~SpriteComponent();
    virtual void draw();
    
protected :

    sf::Image* _image; //Pointeur sur l'Image associee
    sf::Sprite _sprite; //Sprite associe
    sf::Vector2f _position;
};

#endif