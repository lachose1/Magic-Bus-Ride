#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "DrawableComponent.hpp"

class Game;

class SpriteComponent : public DrawableComponent
{
public :

    virtual void draw();
    SpriteComponent(Game* game, std::string filename);
    ~SpriteComponent();
    
protected :

    sf::Image* _image; //Pointeur sur l'Image associee
    sf::Sprite _sprite; //Sprite associe
    sf::Vector2f _position;
};

#endif